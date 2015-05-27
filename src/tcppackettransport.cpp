#include "tcppackettransport.h"

TcpPacketTransport::TcpPacketTransport()
{
    connect(&socket, SIGNAL(connected()), SIGNAL(connected()));
    connect(&socket, SIGNAL(disconnected()), SIGNAL(disconnected()));
    connect(&socket, SIGNAL(readyRead()), SLOT(readFromSocket()));
}

void TcpPacketTransport::makeConnection(QString address, quint16 port)
{
    if (socket.state() != QAbstractSocket::ConnectedState)
        socket.connectToHost(address, port);
}

void TcpPacketTransport::sendPacket(Packet packet)
{
    QByteArray data;
    QHashIterator<QString, QVariant> field(packet.getFields());

    while (field.hasNext()) {
        field.next();

        data += QString("%1: %2").arg(field.key(), field.value().toString()).append("\r\n").toUtf8();
    }

    if (socket.state() == QAbstractSocket::ConnectedState)
        socket.write(data.append("\r\n"));
}

void TcpPacketTransport::parseData()
{
    Packet packet;
    QRegExp fieldPattern("^([A-Za-z0-9\\-]+):\\s(.+)$");
    QStringList fieldLines = QString(dataBuffer).split("\n");

    dataBuffer.clear();

    if (fieldLines.first().startsWith("Asterisk Call Manager")) {
        QString version = fieldLines.takeFirst().replace("Asterisk Call Manager/", QByteArray()).trimmed();

        packet.addField("Event", "Handshake");
        packet.addField("Version", version);
    }

    foreach (QString fieldLine, fieldLines) {
        if (fieldPattern.indexIn(fieldLine) > -1)
            packet.addField(fieldPattern.cap(1), fieldPattern.cap(2).trimmed());
    }

    emit packetReceived(packet);
}

void TcpPacketTransport::readFromSocket()
{
    while (socket.canReadLine()) {
        QByteArray line = socket.readLine();

        if (line != "\r\n")
            dataBuffer += line;
        else
            parseData();
    }
}
