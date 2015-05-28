#ifndef PACKETTRANSPORT
#define PACKETTRANSPORT

#include <QObject>

#include "packet.h"

class PacketTransport : public QObject
{
    Q_OBJECT

public:
    virtual void makeConnection(QString host, quint16 port) = 0;
    virtual void sendPacket(Packet packet) = 0;

signals:
    void connected();
    void disconnected();
    void packetReceived(Packet packet);
};

#endif // PACKETTRANSPORT
