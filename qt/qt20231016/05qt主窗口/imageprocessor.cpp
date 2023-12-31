#include "imageprocessor.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QPrintDialog>
#include <QPrinter>
#include <QPainter>
#include <QColorDialog>
#include <QColor>
#include <QTextList>


ImageProcessor::ImageProcessor(QWidget *parent) :
    QMainWindow(parent)
{

    setWindowTitle(tr("Easy Word"));

    showWidget=new ShowWidget(this);
    setCentralWidget(showWidget);

    //在工具栏上嵌入控件
    //设置字体
    fontLabel1 =new QLabel(tr("字体:"));
    fontComboBox =new QFontComboBox;
    fontComboBox->setFontFilters(QFontComboBox::ScalableFonts);

    fontLabel2 =new QLabel(tr("字号:"));
    sizeComboBox =new QComboBox;
    QFontDatabase db;
    foreach(int size,db.standardSizes())
        sizeComboBox->addItem(QString::number(size));

    //第一个是加粗
    boldBtn =new QToolButton;
    boldBtn->setIcon(QIcon("123.png"));
    boldBtn->setCheckable(true);
    boldBtn->setToolTip("加粗");

    //第二个是斜体
    italicBtn=new QToolButton;
    italicBtn->setIcon(QIcon("123.png"));
    italicBtn->setCheckable(true);
    italicBtn->setToolTip("斜体");

    //第三个是下划线
    underlineBtn =new QToolButton;
    underlineBtn->setIcon(QIcon("123.png"));
    underlineBtn->setCheckable(true);
    underlineBtn->setToolTip("下划线");


    //设置颜色
    colorBtn =new QToolButton;
    colorBtn->setIcon(QIcon("123.png"));
    colorBtn->setCheckable(true);
    colorBtn->setToolTip("设置颜色");

    //排序
    listLabel =new QLabel(tr("排序"));
    listComboBox =new QComboBox;
    listComboBox->addItem("Standard");
    listComboBox->addItem("QTextListFormat::ListDisc");
    listComboBox->addItem("QTextListFormat::ListCircle");
    listComboBox->addItem("QTextListFormat::ListSquare");
    listComboBox->addItem("QTextListFormat::ListDecimal");
    listComboBox->addItem("QTextListFormat::ListLowerAlpha");
    listComboBox->addItem("QTextListFormat::ListUpperAlpha");
    listComboBox->addItem("QTextListFormat::ListLowerRoman");
    listComboBox->addItem("OTextListFormat::ListUpperRoman");

    //绑定信号和槽,可以触发相应
    createActions();
    //构建菜单,也就是最上面的一行
    createMenus();
    //创建工具栏
    createToolBars();
    //让右边的Label显示图片
    if(img.load("123.png"))
    {
        showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
    }

    //文本编辑功能
    connect(fontComboBox,SIGNAL(activated(QString)),this,SLOT(ShowFontComboBox(QString)));
    connect(sizeComboBox,SIGNAL(activated(QString)),this,SLOT(ShowSizeSpinBox(QString)));
    connect(boldBtn,SIGNAL(clicked()),this,SLOT(ShowBoldBtn()));
    connect(italicBtn,SIGNAL(clicked()),this,SLOT(ShowItalicBtn()));
    connect(underlineBtn,SIGNAL(clicked()),this,SLOT(ShowUnderlineBtn()));
    connect(colorBtn,SIGNAL(clicked()),this,SLOT(ShowColorBtn()));

    connect(showWidget->text,&QTextEdit::currentCharFormatChanged,this,&ImageProcessor::ShowCurrentFormatChanged);

    //排序
    connect(listComboBox,SIGNAL(activated(int)),this,SLOT(ShowList(int)));
    connect(showWidget->text->document(),SIGNAL(undoAvailable(bool)),redoAction,SLOT(setEnabled(bool)));
    connect(showWidget->text->document(),SIGNAL(redoAvailable(bool)),redoAction,SLOT(setEnabled(bool)));
    connect(showWidget->text,SIGNAL(cursorPositionChanged()),this,SLOT(ShowCursorPositionChanged()));

}
//动作的实现
//给动作绑定信号和槽
void ImageProcessor::createActions (){

    //“打开”动作
    openFileAction =new QAction(QIcon("123.png"),tr("打开"),this);
    //设置快捷键
    openFileAction->setShortcut(tr("Ctrl+o"));
    //设置状态提示文本
    openFileAction->setStatusTip(tr("打开一个文件"));
    connect(openFileAction,SIGNAL(triggered()),this,SLOT(ShowOpenFile()));

    //“新建”动作
    NewFileAction =new QAction(QIcon("123.png"),tr("新建"),this);
    NewFileAction->setShortcut(tr("Ctrl+N"));
    NewFileAction->setStatusTip(tr("新建一个文件"));
    connect(NewFileAction,SIGNAL(triggered()),this,SLOT(ShowNewFile()));
    //“退出”动作
    exitAction =new QAction(tr("退出"),this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip(tr("退出程序"));
    connect(exitAction,SIGNAL(triggered()),this,SLOT(close()));
    //“复制”动作
    copyAction =new QAction(QIcon("123.png"),tr("复制"),this);
    copyAction->setShortcut(tr("Ctrl+C"));
    copyAction->setStatusTip(tr("复制文件"));
    connect(copyAction,SIGNAL(triggered()),showWidget->text,SLOT(copy()));
    //“剪切”动作
    cutAction =new QAction(QIcon("123.png"),tr("剪切"),this);
    cutAction->setShortcut(tr("trl+x"));
    cutAction->setStatusTip(tr("剪切文件"));
    connect(cutAction,SIGNAL(triggered()),showWidget->text,SLOT(cut()));
    //“粘贴”动作
    pasteAction =new QAction(QIcon("123.png"),tr("粘贴"),this);
    pasteAction->setShortcut(tr("Ctrl+V"));
    pasteAction->setStatusTip(tr("粘贴文件"));
    connect(pasteAction,SIGNAL(triggered()),showWidget->text,SLOT(paste()));
    //“关于”动作
    aboutAction =new QAction(tr("关于"),this);
    connect(aboutAction,SIGNAL(triggered()),this,SLOT(aboutQt()));

    //“打印文本”动作
    PrintTextAction =new QAction(QIcon("123.png"),tr("打印文本"),this);
    PrintTextAction->setStatusTip(tr("打印一个文本"));
    connect(PrintTextAction,SIGNAL(triggered()),this,SLOT(ShowPrintText()));

    //“打印图像”动作
    PrintImageAction =new QAction(QIcon("123.png"),tr("打印图像"),this);
    PrintImageAction->setStatusTip(tr("打印一幅图像"));
    connect(PrintImageAction,SIGNAL(triggered()),this,SLOT(ShowPrintImage()));

    //“放大”动作
    zoomInAction =new QAction(QIcon("123.png"),tr("放大"),this);
    zoomInAction->setStatusTip(tr("放大一张图片"));
    connect(zoomInAction,SIGNAL(triggered()),this,SLOT(ShowZoomIn()));

    //“缩小”动作
    zoomOutAction=new QAction(QIcon("123.png"),tr("缩小"),this);
    zoomOutAction->setStatusTip(tr("缩小一张图片"));
    connect(zoomOutAction,SIGNAL(triggered()),this,SLOT(ShowZoomOut()));

    //实现图像旋转的动作(Action)
    //旋转90°
    rotate90Action =new QAction(QIcon("123.png"),tr("旋转 90"),this);
    rotate90Action->setStatusTip(tr("将一幅图旋转 90°"));
    connect(rotate90Action,SIGNAL(triggered()),this,SLOT(showRotate90()));
    //旋转180
    rotate180Action =new QAction(QIcon("123.png"),tr("旋转180°"),this);
    rotate180Action->setStatusTip(tr("将一幅图旋转 180°"));
    connect(rotate180Action,SIGNAL(triggered()),this,SLOT(ShowRotate180()));
    //旋转270°
    rotate270Action =new QAction(QIcon("123.png"),tr("旋转270°"),this);
    rotate270Action->setStatusTip(tr("将一幅图旋转 270°"));
    connect(rotate270Action,SIGNAL(triggered()),this,SLOT(ShowRotate270()));
    //实现图像镜像的动作(Action)
    //纵向镜像
    mirrorVerticalAction =new QAction(QIcon("123.png"),tr ("纵向镜像"),this);
    mirrorVerticalAction->setStatusTip(tr("对一张图做纵向镜像"));
    connect(mirrorVerticalAction,SIGNAL(triggered()),this,SLOT(ShowMirrorVertical()));
    //横向镜像
    mirrorHorizontalAction =new QAction(QIcon("123.png"),tr("横向镜像"),this);
    mirrorHorizontalAction->setStatusTip(tr("对一张图做横向镜像"));
    connect(mirrorHorizontalAction,SIGNAL(triggered()),this,SLOT(ShowMirrorHorizontal()));

    //实现撤销和恢复的动作 (Action)//撤销和恢复
    undoAction =new QAction(QIcon("123.png"),"撤销",this);
    connect(undoAction,SIGNAL(triggered()),showWidget->text,SLOT(undo()));

    redoAction =new QAction(QIcon("123.png"),"重做",this);
    connect(redoAction,SIGNAL(triggered()),showWidget->text,SLOT(redo()));

    //排序:左对齐、右对齐、居中和两端对齐
    actGrp =new QActionGroup(this);
    leftAction =new QAction(QIcon("123.png"),"左对齐",actGrp);
    leftAction->setCheckable(true);

    rightAction =new QAction(QIcon("123.png"),"右对齐",actGrp);
    rightAction->setCheckable(true);

    centerAction =new QAction(QIcon("123.png"),"居中",actGrp);
    centerAction->setCheckable(true);

    justifyAction =new QAction(QIcon("123.png"),"两端对齐",actGrp);
    justifyAction->setCheckable(true);

    connect(actGrp,SIGNAL(triggered(QAction*)),this,SLOT(ShowAlignment(QAction*)));

}
//菜单的实现
void ImageProcessor::createMenus(){
    //文件菜单
    fileMenu =menuBar()->addMenu(tr("文件"));
    fileMenu->addAction(openFileAction);
    fileMenu->addAction(NewFileAction);
    fileMenu->addAction(PrintTextAction);
    fileMenu->addAction(PrintImageAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    //缩放菜单
    zoomMenu =menuBar()->addMenu(tr("编辑"));
    zoomMenu->addAction(copyAction);
    zoomMenu->addAction(cutAction);
    zoomMenu->addAction(pasteAction);
    zoomMenu->addAction(aboutAction);
    zoomMenu->addSeparator();
    zoomMenu->addAction(zoomInAction);
    zoomMenu->addAction(zoomOutAction);
    //旋转菜单
    rotateMenu=menuBar()->addMenu(tr("旋转"));
    rotateMenu->addAction(rotate90Action);
    rotateMenu->addAction(rotate180Action);
    rotateMenu->addAction(rotate270Action);
    //镜像菜单
    mirrorMenu =menuBar()->addMenu(tr("镜像"));
    mirrorMenu->addAction(mirrorVerticalAction);
    mirrorMenu->addAction(mirrorHorizontalAction);


}
//工具栏的实现
void ImageProcessor::createToolBars(){

    //文件工具条
    fileTool =addToolBar("File");
    fileTool->addAction(openFileAction);
    fileTool->addAction(NewFileAction);
    fileTool->addAction(PrintTextAction);
    fileTool->addAction(PrintImageAction);
    fileTool->setAllowedAreas(Qt::TopToolBarArea|Qt::LeftToolBarArea);
    fileTool->setMovable(false);
    //编辑工具条
    zoomTool =addToolBar("Edit");
    zoomTool->addAction(copyAction);
    zoomTool->addAction(cutAction);
    zoomTool->addAction(pasteAction);
    zoomTool->addSeparator();
    zoomTool->addAction(zoomInAction);
    zoomTool->addAction(zoomOutAction);
    //旋转工具条
    rotateTool =addToolBar("rotate");
    rotateTool->addAction(rotate90Action);
    rotateTool->addAction(rotate180Action);
    rotateTool->addAction(rotate270Action);
    //撤销和重做工具条
    doToolBar =addToolBar("doEdit");
    doToolBar->addAction(undoAction);
    doToolBar->addAction(redoAction);

    //字体工具条
    fontToolBar =addToolBar("Font");
    fontToolBar->addWidget(fontLabel1);
    fontToolBar->addWidget(fontComboBox);
    fontToolBar->addWidget(fontLabel2);
    fontToolBar->addWidget(sizeComboBox);
    fontToolBar->addSeparator();
    fontToolBar->addWidget(boldBtn);
    fontToolBar->addWidget(italicBtn);
    fontToolBar->addWidget(underlineBtn);
    fontToolBar->addSeparator();
    fontToolBar->addWidget(colorBtn);

    //排序工具条
    listToolBar =addToolBar("list");
    listToolBar->addWidget(listLabel);
    listToolBar->addWidget(listComboBox);
    listToolBar->addSeparator();
    listToolBar->addActions(actGrp->actions());


}

void ImageProcessor::aboutQt(){
    QMessageBox::information(this, "关于", "关于消息");
}

void ImageProcessor::ShowNewFile(){
    ImageProcessor *newImgProcessor =new ImageProcessor;
    newImgProcessor->show();
}
//加载文件
void ImageProcessor::loadFile(QString filename){

    printf("file name:%s\n",filename.data());

    QFile file(filename);

    if(file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QTextStream textStream(&file);
        while(!textStream.atEnd()){
            //一行一行读取追加到textFile中
            showWidget->text->append(textStream.readLine());
            printf("read line\n");
        }
        printf("end\n");
    }


}
//打开文件
void ImageProcessor::ShowOpenFile(){
    fileName =QFileDialog::getOpenFileName(this);
    if(!fileName.isEmpty())
    {
        if(showWidget->text->document()->isEmpty()){
            loadFile(fileName);
        }
        else{
            ImageProcessor *newImgProcessor =new ImageProcessor;
            newImgProcessor->show();
            newImgProcessor->loadFile(fileName);
        }
    }



}


void ImageProcessor::ShowPrintText(){
    QPrinter printer;

    QPrintDialog printDialog(&printer,this);
    if(printDialog.exec()){
        QTextDocument *doc =showWidget->text->document();
        doc->print(&printer);
    }
}

void ImageProcessor::ShowPrintImage() {
    QPrinter printer;
    QPrintDialog printDialog(&printer, this);
    if (printDialog.exec()) {
        QPainter painter(&printer);
        QRect rect = painter.viewport();
        QSize size = img.size();
        size.scale(rect.size(), Qt::KeepAspectRatio);
        painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
        painter.setWindow(img.rect());
        painter.drawImage(0, 0, img);
    }
}
//图像放大和缩小不是很符合意愿
void ImageProcessor::ShowZoomIn(){

    if(img.isNull()){
        return;
    }

    QSize newSize(img.width() * 2, img.height() * 2);
    img = img.scaled(newSize, Qt::KeepAspectRatio);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

void ImageProcessor::ShowZoomOut(){
    if(img.isNull())
        return;

    QSize newSize(img.width() * 0.5, img.height() * 0.5);
    img = img.scaled(newSize, Qt::KeepAspectRatio);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));


}
void ImageProcessor::showRotate90(){
    if(img.isNull())
        return;
    QMatrix matrix;
    matrix.rotate(90);
    img = img.transformed(matrix);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}
void ImageProcessor::ShowRotate180(){
    if(img.isNull())
        return;
    QMatrix matrix;
    matrix.rotate(180);
    img = img.transformed(matrix);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

void ImageProcessor::ShowRotate270(){
    if(img.isNull())
        return;
    QMatrix matrix;
    matrix.rotate(270);
    img = img.transformed(matrix);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}



void ImageProcessor::ShowMirrorVertical(){

    if(img.isNull())
        return;
    img=img.mirrored(false,true);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}


void ImageProcessor::ShowMirrorHorizontal(){

    if(img.isNull())
        return;
    img=img.mirrored(true,false);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));

}

void ImageProcessor::mergeFormat(QTextCharFormat format){
    QTextCursor cursor =showWidget->text->textCursor();
    if(!cursor.hasSelection())
        cursor.select(QTextCursor::WordUnderCursor);
    cursor.mergeCharFormat(format);
    showWidget->text->mergeCurrentCharFormat(format);
}


void ImageProcessor::ShowFontComboBox(QString comboStr) //设置字体
{
    QTextCharFormat fmt;
    fmt.setFontFamily(comboStr);
    mergeFormat(fmt);       //将新的格式应用到光标选区内的字符
}

void ImageProcessor::ShowSizeSpinBox(QString spinValue) //设置字号
{
    QTextCharFormat fmt;
    fmt.setFontPointSize(spinValue.toFloat());
    showWidget->text->mergeCurrentCharFormat(fmt);
}


void ImageProcessor::ShowBoldBtn()//设置文字显示加粗
{
    QTextCharFormat fmt;
    fmt.setFontWeight(boldBtn->isChecked()?QFont::Bold:QFont::Normal);
    showWidget->text->mergeCurrentCharFormat(fmt);
}

void ImageProcessor::ShowItalicBtn()//设置文字显示斜体
{
    QTextCharFormat fmt;
    fmt.setFontItalic(italicBtn->isChecked());
    showWidget->text->mergeCurrentCharFormat(fmt);
}

void ImageProcessor::ShowUnderlineBtn()//设置文字加下画线
{
    QTextCharFormat fmt;
    fmt.setFontUnderline(underlineBtn->isChecked());
    showWidget->text->mergeCurrentCharFormat(fmt);
}


void ImageProcessor::ShowColorBtn()
//设置文字颜色
{

    QColor color=QColorDialog::getColor(Qt::red,this);
    if(color.isValid())
    {
        QTextCharFormat fmt;
        fmt.setForeground(color);
        showWidget->text->mergeCurrentCharFormat(fmt);
    }
}

//设置字体颜色
void ImageProcessor::ShowCurrentFormatChanged(const QTextCharFormat &fmt)
{
    fontComboBox->setCurrentIndex(fontComboBox->findText(fmt.fontFamily()));
    sizeComboBox->setCurrentIndex(sizeComboBox->findText(QString::number(fmt.fontPointSize())));
    boldBtn->setChecked(fmt.font().bold());
    italicBtn->setChecked(fmt.fontItalic());
    underlineBtn->setChecked(fmt.fontUnderline());
}



void ImageProcessor::ShowAlignment(QAction *act){
    if(act==leftAction)
        showWidget->text->setAlignment(Qt::AlignLeft);
    if(act==rightAction)
        showWidget->text->setAlignment(Qt::AlignRight);
    if(act==centerAction)
        showWidget->text->setAlignment(Qt::AlignCenter);
    if(act==justifyAction)
        showWidget->text->setAlignment(Qt::AlignJustify);
}

void ImageProcessor::ShowCursorPositionChanged(){

    if(showWidget->text->alignment()==Qt::AlignLeft)
        leftAction->setChecked(true);
    if(showWidget->text->alignment()==Qt::AlignRight)
        rightAction->setChecked(true);
    if(showWidget->text->alignment()==Qt::AlignCenter)
        centerAction->setChecked(true);
    if(showWidget->text->alignment()==Qt::AlignJustify)
        justifyAction->setChecked(true);
}

void ImageProcessor::ShowList(int index){


    QTextCursor cursor=showWidget->text->textCursor();

    if(index!=0)
    {
        QTextListFormat::Style style=QTextListFormat::ListDisc;
        switch(index)//设置 style 属性值
        {
        default:
        case 1:
            style=QTextListFormat::ListDisc; break;
        case 2:
            style=QTextListFormat::ListCircle; break;
        case 3:
            style=QTextListFormat::ListSquare; break;
        case 4:
            style=QTextListFormat::ListDecimal; break;
        case 5:
            style=QTextListFormat::ListLowerAlpha; break;
        case 6:
            style=QTextListFormat::ListUpperAlpha; break;
        case 7:
            style=QTextListFormat::ListLowerRoman; break;
        case 8:
            style=QTextListFormat::ListUpperRoman; break;
        }
        cursor.beginEditBlock();//设置缩进值

        QTextBlockFormat blockFmt=cursor.blockFormat();
        QTextListFormat listFmt;

        if(cursor.currentList()){

            listFmt= cursor.currentList()->format();
        }
        else{

            listFmt.setIndent(blockFmt.indent()+1);
            blockFmt.setIndent(0);
            cursor.setBlockFormat(blockFmt);
        }
        listFmt.setStyle(style);
        cursor.createList(listFmt);

        cursor.endEditBlock();

    }else{
        QTextBlockFormat bfmt;
        bfmt.setObjectIndex(-1);
        cursor.mergeBlockFormat(bfmt);
    }
}


