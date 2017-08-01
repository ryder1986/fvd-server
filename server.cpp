#include "server.h"

Server::Server(QObject *parent) : QObject(parent)
{
    bool ret=false;
    server=new QTcpServer();
    ret=server->listen(QHostAddress::Any,12345);
    if(ret){
        qDebug()<<"listen"<<server->serverPort();
    }else
    {
          qDebug()<<"listen fail";
    }
    connect(server, &QTcpServer::newConnection, this, &Server::reply);

}

