#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>

int main(void)
{

	QFile sourceFile("abc.txt");
	QFile destinationFile("abc_new_qt.txt");
	QList<int>cache;
	if (!sourceFile.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		qDebug() << "Failed to open source file.";
		return -1;
	}

	if (!destinationFile.open(QIODevice::WriteOnly | QIODevice::Text))
	{
		qDebug() << "Failed to open destination file.";
		sourceFile.close();
		return -2;
	}

	QTextStream sourceTextStream(&sourceFile);
	QTextStream destinationTextStream(&destinationFile);

	while (!sourceTextStream.atEnd())
	{

		QString line = sourceTextStream.readLine();
		QStringList list = line.split(",");
		for (auto element : list) {
			bool ok;
			int elementInt = element.trimmed().toInt(&ok);
			if (ok) {
				cache.append(elementInt);
			}
			destinationTextStream << elementInt << endl;
		}

		
	}
	sourceFile.close();
	destinationFile.close();

	for (auto element : cache) {
		qDebug() << element;
	}

	return 0;
}