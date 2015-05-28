#include <QRegularExpression>
#include <QDebug>

#include "tcppackettransport.h"

TcpPacketTransport::TcpPacketTransport()
{
    connect(&socket, SIGNAL(connected()), SIGNAL(connected()));
    connect(&socket, SIGNAL(disconnected()), SIGNAL(disconnected()));
    connect(&socket, SIGNAL(readyRead()), SLOT(readFromSocket()));

    connect(&socket, static_cast<void (QTcpSocket::*) (QAbstractSocket::SocketError)>(&QTcpSocket::error), [=] (QAbstractSocket::SocketError socketError) {
        qDebug() << "Socket Error:" << socketError;
    });
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
    QStringList fieldLines = QString(dataBuffer.trimmed()).split("\r\n");
    QRegularExpression fieldPattern("^([A-Za-z0-9\\-]+):\\s(.+)$");

    dataBuffer.clear();

    foreach (QString fieldLine, fieldLines) {
        QRegularExpressionMatch patternMatch = fieldPattern.match(fieldLine);

        if (patternMatch.hasMatch())
            packet.addField(patternMatch.captured(1), patternMatch.captured(2));
    }

    emit packetReceived(packet);
}

void TcpPacketTransport::readFromSocket()
{
    while (socket.canReadLine()) {
        QByteArray line = socket.readLine();

        if (line.startsWith("Asterisk Call Manager")) {
            line.replace("Asterisk Call Manager/", QByteArray()).trimmed();

            dataBuffer += "Event: Handshake\r\n";
            dataBuffer += "Version: " + line + "\r\n";

            parseData();

            continue;
        }

        if (line != "\r\n")
            dataBuffer += line;
        else
            parseData();
    }
}
