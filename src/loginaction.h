#ifndef LOGINACTION_H
#define LOGINACTION_H

#include "action.h"

class LoginAction : public Action
{
public:
    LoginAction();

    void setUsername(QString username);
    void setSecret(QString secret);
};

#endif // LOGINACTION_H
