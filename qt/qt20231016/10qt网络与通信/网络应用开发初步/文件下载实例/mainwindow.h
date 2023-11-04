#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QFile>
#include <QMainWindow>
#include <QUrl>
#include <QNetworkReply>
#include <QFileInfo>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void startRequest(QUrl url);

private  slots:
    void httpFinished();
    void httpReadyRead();
    void updateDataReadProgress(qint64,qint64);
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    QNetworkReply *reply;
    QUrl url;
    QFile *file;
    QNetworkAccessManager *manager;
};

#endif // MAINWINDOW_H
