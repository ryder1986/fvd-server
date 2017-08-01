#include "broadcast_buffer.h"

broadcast_buffer::broadcast_buffer(QObject *parent) : QObject(parent)
{
    timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(send_buffer()));
    udpSocket = new QUdpSocket(this);
    timer->start(1000);

}

