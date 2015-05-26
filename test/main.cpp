#include <iostream>
#include <QTest>

#include "loginactiontest.h"
#include "logoffactiontest.h"

int main(int argc, char *argv[])
{
    QTest::qExec(new LoginActionTest, argc, argv); std::cout << std::endl;
    QTest::qExec(new LogoffActionTest, argc, argv); std::cout << std::endl;

    return 0;
}
