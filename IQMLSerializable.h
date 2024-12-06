#ifndef IQMLSERIALIZABLE_H
#define IQMLSERIALIZABLE_H

#include <QVariantMap>


class IQMLSerializable {
    virtual QVariantMap serialize();
};

#endif // IQMLSERIALIZABLE_H
