#include <QThread>
#include <QtDebug>
#include <QTextStream>
#include <QMutex>

class WorkThread : public QThread
{
public:
    explicit WorkThread();
protected:
    void run();
private:
    QMutex mutex;
};


WorkThread::WorkThread()
{


}
void WorkThread::run(){
    while(true){


        for(int n=0;n<10;n++){

            mutex.lock();
            QTextStream out(stdout);

            out << n << n << n << n << n << n << n << n << endl;
            out.flush();
            mutex.unlock();
            QThread::sleep(1);
        }
    }
}


int main(void)
{
    int thread_num=2;
    WorkThread *workThread[thread_num];
    for(int i=0;i<thread_num;i++){
        workThread[i]=new WorkThread();
        workThread[i]->start();

    }

    workThread[0]->wait();
    return 0;
}
