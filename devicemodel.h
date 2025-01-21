#ifndef DEVICEMODEL_H
#define DEVICEMODEL_H

#include <QPrinterInfo>
#include <QAbstractListModel>

class DeviceModel : public QAbstractListModel{
    Q_OBJECT
    using BaseClass = QAbstractListModel;
public:
    explicit DeviceModel(QObject *parent = nullptr);
    // QAbstractItemModel interface
    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
};

#endif // DEVICEMODEL_H
