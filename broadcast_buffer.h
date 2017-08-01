#ifndef BROADCAST_BUFFER_H
#define BROADCAST_BUFFER_H

#include <QObject>
#include <QTimer>
#include <QtNetwork>
#include <QNetworkInterface>
class broadcast_buffer : public QObject
{
    Q_OBJECT
public:
    explicit broadcast_buffer(QObject *parent = 0);

signals:

public slots:
    void send_buffer()
    {
      //  qDebug()<<"time out ";
       datagram = "ip 192.168.1.214 ";

        datagram.clear();
        QList <QNetworkInterface>list_interface=QNetworkInterface::allInterfaces();
        foreach (QNetworkInterface i, list_interface) {
            if(i.name()!="lo"){
                QList<QNetworkAddressEntry> list_entry=i.addressEntries();
                foreach (QNetworkAddressEntry e, list_entry) {
                    if(e.ip().protocol()==QAbstractSocket::IPv4Protocol)
                    {
                    //    qDebug()<<e.ip()<<e.netmask()<<e.broadcast();
                        datagram.append(QString(e.ip().toString())).append(QString(",")).\
                                append(QString(e.netmask().toString())).append(QString(",")).append(QString(e.broadcast().toString()));

                //    qDebug()<<datagram;
                    }

                }
            }
        }


        udpSocket->writeDatagram(datagram.data(), datagram.size(),
                                 QHostAddress::Broadcast, 45454);
    }

private:
    QTimer *timer;
    int     messageNo;
  QByteArray datagram;
    QUdpSocket *udpSocket;
};

#endif // BROADCAST_BUFFER_H
