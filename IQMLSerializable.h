#ifndef IQMLSERIALIZABLE_H
#define IQMLSERIALIZABLE_H

#include <QVariantMap>


class IQMLSerializable {
    virtual QVariantMap serialize() = 0;
};

#endif // IQMLSERIALIZABLE_H
