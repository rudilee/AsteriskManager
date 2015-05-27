#include "loginaction.h"

LoginAction::LoginAction(QString actionId) : Action("Login", actionId)
{
}

void LoginAction::setUsername(QString username)
{
    addField("Username", username);
}

void LoginAction::setSecret(QString secret)
{
    addField("Secret", secret);
}
