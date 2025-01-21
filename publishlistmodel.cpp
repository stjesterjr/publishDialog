#include "publishlistmodel.h"

PublishListModel::PublishListModel(QObject* parent)
    : BaseClass(parent)
{
    m_publishListNames.push_back(tr("<Current>"));
    m_publishListNames.push_back(tr("<Last>"));
    m_publishListNames.push_back(tr("<a>"));
    m_publishListNames.push_back(tr("<b>"));
    m_publishListNames.push_back(tr("<c>"));
    m_publishListNames.push_back(tr("<d>"));
    m_publishListNames.push_back(tr("<e>"));
}

int PublishListModel::rowCount(const QModelIndex &parent) const
{
    return m_publishListNames.count();
}
QVariant PublishListModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid() || role != Qt::DisplayRole)
        return {};
    return m_publishListNames[index.row()];
}
