#include "packet.h"

Packet::Packet(Type type) : m_type(type)
{
}

void Packet::addField(QString key, QVariant value)
{
    fields.insert(key, convertToString(value));
}

void Packet::addVariable(QString variable, QVariant value)
{
    fields.insertMulti("Variable", QString("%1=%2").arg(variable, convertToString(value)));
}

void Packet::setFields(QMultiHash<QString, QVariant> fields)
{
    this->fields.unite(fields);
}

Packet::Type Packet::type()
{
    return m_type;
}

QMultiHash<QString, QVariant> Packet::getFields()
{
    return fields;
}

QVariant Packet::field(QString key)
{
    return fields.value(key);
}

QString Packet::convertToString(QVariant value)
{
    if ((QMetaType::Type) value.type() == QMetaType::Bool)
        return value.toBool() ? "True" : "False";

    return value.toString();
}
