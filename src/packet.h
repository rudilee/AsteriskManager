#ifndef PACKET_H
#define PACKET_H

#include <QVariant>
#include <QMultiHash>

class Packet
{
public:
    enum Type {
        Action,
        Response,
        Event
    };

    explicit Packet(Type type = Action);

    virtual void addField(QString key, QVariant field);
    void addVariable(QString variable, QVariant field);
    void setFields(QMultiHash<QString, QVariant> fields);

    Type type();
    QMultiHash<QString, QVariant> getFields();
    QVariant field(QString key);

protected:
    Type m_type;
    QMultiHash<QString, QVariant> fields;

    QString convertToString(QVariant field);
};

#endif // PACKET_H
