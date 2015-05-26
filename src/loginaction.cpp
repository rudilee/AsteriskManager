#include "loginaction.h"

LoginAction::LoginAction() : Action("Login")
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
