#ifndef TCPPACKETTRANSPORT_H
#define TCPPACKETTRANSPORT_H

#include <QTcpSocket>

#include "packettransport.h"

class TcpPacketTransport : public PacketTransport
{
public:
    explicit TcpPacketTransport();

    void makeConnection(QString address, quint16 port);
    void sendPacket(Packet packet);

private:
    QTcpSocket socket;
    QByteArray dataBuffer;

    void parseData();

private slots:
    void readFromSocket();

signals:
    void connected();
    void disconnected();
};

#endif // TCPPACKETTRANSPORT_H
