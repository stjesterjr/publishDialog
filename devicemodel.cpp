#include "devicemodel.h"

DeviceModel::DeviceModel(QObject *parent)
    : BaseClass(parent)
{
}

int DeviceModel::rowCount(const QModelIndex &parent) const
{
    return QPrinterInfo::availablePrinterNames().count();
}

QVariant DeviceModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid() || role != Qt::DisplayRole)
        return {};
    return QPrinterInfo::availablePrinterNames().at(index.row());
}
