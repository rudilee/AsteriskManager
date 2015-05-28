#include <QUuid>

#include "action.h"

Action::Action(QString actionName, QString actionId, QObject *parent) : QObject(parent), Packet(Packet::Action)
{
    if (actionId.isEmpty())
        this->actionId = QUuid::createUuid().toString();

    addField("Action", actionName);
    addField("ActionID", this->actionId);
}

QString Action::getActionId()
{
    return actionId;
}
