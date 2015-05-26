#ifndef PACKETTRANSPORT
#define PACKETTRANSPORT

#include <QObject>

#include "packet.h"

class PacketTransport : public QObject
{
    Q_OBJECT

public:
    virtual void sendPacket(Packet packet) = 0;

signals:
    void packetReceived(Packet packet);
};

#endif // PACKETTRANSPORT
