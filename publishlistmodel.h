#ifndef PUBLISHLISTMODEL_H
#define PUBLISHLISTMODEL_H

#include <QAbstractListModel>

class PublishListModel : public QAbstractListModel
{
    Q_OBJECT
    using BaseClass = QAbstractListModel;
public:
    explicit PublishListModel(QObject* parent = nullptr);
    // QAbstractItemModel interface
    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;

private:
    QStringList m_publishListNames;
};

#endif // PUBLISHLISTMODEL_H
