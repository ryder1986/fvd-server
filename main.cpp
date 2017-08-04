#include <QCoreApplication>
#include "server.h"
#include "broadcast_buffer.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    broadcast_buffer *b=new broadcast_buffer();
    qDebug()<<"1";
    Server *s=new Server();
    qDebug()<<"2";
    return a.exec();
}

