#include "publishlistwidget.h"


#include <QHBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include "publishlistmodel.h"

PublishListWidget::PublishListWidget(QWidget *parent)
    : BaseClass(parent)
    , m_label{new QLabel(tr("Sheet &List:"), this)}
    , m_comboBox{new QComboBox(this)}
    , m_model{new PublishListModel(this)}
{
    m_label->setBuddy(m_comboBox);

    auto layout = new QHBoxLayout(this);
    layout->setContentsMargins(0,0,0,0);
    layout->addWidget(m_label);
    layout->addWidget(m_comboBox);

    m_comboBox->setStyleSheet("QComboBox { padding-top: 3px; padding-bottom: 3px; }");
    m_comboBox->setModel(m_model);

    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
}
