#ifndef LOGINACTION_H
#define LOGINACTION_H

#include "action.h"

class LoginAction : public Action
{
public:
    explicit LoginAction(QString actionId = QString());

    void setUsername(QString username);
    void setSecret(QString secret);
};

#endif // LOGINACTION_H
