#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QtNetwork>
class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0);
#if 0
//    void reply()
//    {
//        qDebug()<<"send one";
//        QByteArray block;
//        QDataStream out(&block, QIODevice::WriteOnly);
//        out.setVersion(QDataStream::Qt_4_0);
//        out<<(quint16)0;
//        out << QString("123456789");
//        out.device()->seek(0);
//        out<<(quint16)(block.size()-sizeof(quint16));

//        QTcpSocket *skt = server->nextPendingConnection();
//        connect(skt, &QAbstractSocket::disconnected,
//                skt, &QObject::deleteLater);

//        skt->write(block);
//        skt->disconnectFromHost();
//    }
#endif
#if 0
    void reply()
    {
        qDebug()<<"send one";
        QByteArray block;
//        QDataStream out(&block, QIODevice::WriteOnly);
//        out.setVersion(QDataStream::Qt_4_0);
//        out<<(quint16)0;
//        out << QString("123456789");
//        out.device()->seek(0);
//        out<<(quint16)(block.size()-sizeof(quint16));

        QString str("12345");
        block.append(str);
        QTcpSocket *skt = server->nextPendingConnection();
        connect(skt, &QAbstractSocket::disconnected,
                skt, &QObject::deleteLater);

        skt->write(block);
        skt->disconnectFromHost();
    }
#endif
#if 1
    void reply()
    {
        qDebug()<<"send one";
        QByteArray block;
//        QDataStream out(&block, QIODevice::WriteOnly);
//        out.setVersion(QDataStream::Qt_4_0);
//        out<<(quint16)0;
//        out << QString("123456789");
//        out.device()->seek(0);
//        out<<(quint16)(block.size()-sizeof(quint16));

        QString str("1234567890");
        block.append(str);
        QTcpSocket *skt = server->nextPendingConnection();
        connect(skt, &QAbstractSocket::disconnected,
                skt, &QObject::deleteLater);

        skt->write(block);





         skt->disconnectFromHost();
    }
#endif
signals:

public slots:
private:
    QTcpServer *server;
};

#endif // SERVER_H
