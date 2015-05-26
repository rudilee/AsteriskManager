#ifndef LOGOFFACTIONTEST_H
#define LOGOFFACTIONTEST_H

#include <QObject>

class LogoffActionTest : public QObject
{
    Q_OBJECT
public:
    explicit LogoffActionTest(QObject *parent = 0);

private Q_SLOTS:
    void testLogoffMessageSent();
};

#endif // LOGOFFACTIONTEST_H
