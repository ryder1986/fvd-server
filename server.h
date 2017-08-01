#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QtNetwork>
class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0);
    void reply()
    {
        qDebug()<<"send one";
        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_4_0);

        out << "12345";


        QTcpSocket *clientConnection = server->nextPendingConnection();
        connect(clientConnection, &QAbstractSocket::disconnected,
                clientConnection, &QObject::deleteLater);


        clientConnection->write(block);
        clientConnection->disconnectFromHost();
    }

signals:

public slots:
private:
    QTcpServer *server;
};

#endif // SERVER_H
