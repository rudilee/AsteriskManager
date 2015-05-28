#ifndef TCPPACKETTRANSPORT_H
#define TCPPACKETTRANSPORT_H

#include <QTcpSocket>

#include "packettransport.h"

class TcpPacketTransport : public PacketTransport
{
    Q_OBJECT

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
};

#endif // TCPPACKETTRANSPORT_H
