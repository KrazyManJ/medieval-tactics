#include "IQMLSerializable.h"

#ifndef POSITION_H
#define POSITION_H

#endif // POSITION_H

// TODO: make inherit IQMLSerializable
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
