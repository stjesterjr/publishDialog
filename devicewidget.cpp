#include "devicewidget.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include "DeviceModel.h"

DeviceWidget::DeviceWidget(QWidget *parent)
    : BaseClass(parent)
    , m_label{new QLabel(tr("&Publish to:"), this)}
    , m_comboBox{new QComboBox(this)}
    , m_button{new QPushButton(tr("&Options..."), this)}
    , m_model{new DeviceModel(this)}
{
    auto layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(m_label);
    layout->addWidget(m_comboBox);
    layout->addWidget(m_button);

    m_label->setBuddy(m_comboBox);
    m_comboBox->addItem(tr("Plotter from Layout Page Setup"));
    m_comboBox->setStyleSheet("QComboBox { padding-top: 3px; padding-bottom: 3px; }");
    m_comboBox->setModel(m_model);

    //m_button->setStyleSheet("QPushButton { padding-top: 0px; padding-bottom: 0px; }");

    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
}
