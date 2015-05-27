#ifndef LOGOFFACTION_H
#define LOGOFFACTION_H

#include "action.h"

class LogoffAction : public Action
{
public:
    explicit LogoffAction(QString actionId = QString());
};

#endif // LOGOFFACTION_H
