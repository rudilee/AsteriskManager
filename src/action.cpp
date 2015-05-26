#include <QUuid>

#include "action.h"

Action::Action(QString actionName, QObject *parent) : QObject(parent), Packet(Packet::Action),
    actionId(QUuid::createUuid().toString())
{
    addField("Action", actionName);
    addField("ActionID", actionId);
}

QString Action::getActionId()
{
    return actionId;
}
