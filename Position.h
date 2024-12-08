#include "IQMLSerializable.h"

#ifndef POSITION_H
#define POSITION_H

#endif // POSITION_H

struct Position {
    int row;
    int column;

    QVariantMap serialize() {
        QVariantMap obj;
        obj["row"] = row;
        obj["column"] = column;
        return obj;
    };
};
