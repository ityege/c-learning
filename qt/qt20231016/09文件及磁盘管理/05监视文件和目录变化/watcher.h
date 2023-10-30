#ifndef WATCHER_H
#define WATCHER_H

#include <QWidget>
#include <QLabel>
#include <QFileSystemWatcher>

class Watcher : public QWidget
{
    Q_OBJECT
public:
    explicit Watcher(QWidget *parent = 0);

signals:

public slots:
    void directoryChanged(QString path);


private:
    QLabel *pathLabel;
    QFileSystemWatcher fsWatcher;

};

#endif // WATCHER_H
