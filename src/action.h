#ifndef ACTION_H
#define ACTION_H

#include "packet.h"

class Action : public QObject, public Packet
{
    Q_OBJECT

public:
    explicit Action(QString actionName, QObject *parent = 0);

    QString getActionId();

protected:
    QString actionId;

signals:
    void responseReceived(Packet response);
};

#endif // ACTION_H
