#ifndef LOGINACTIONTEST_H
#define LOGINACTIONTEST_H

#include <QObject>

class LoginActionTest : public QObject
{
    Q_OBJECT

public:
    explicit LoginActionTest(QObject *parent = 0);

private Q_SLOTS:
    void testLoginMessageSent();
};

#endif // LOGINACTIONTEST_H
