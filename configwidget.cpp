#include "configwidget.h"

#include <QLabel>
#include <QSpinBox>
#include <QCheckBox>
#include <QHBoxLayout>

ConfigWidget::ConfigWidget(QWidget *parent)
    : QWidget{parent}
{
    auto layout = new QHBoxLayout(this);
    m_copyNumberLabel = new QLabel(tr("&Number of copies:"), this);
    m_copyNumberSpinBox = new QSpinBox(this);
    m_multiCheckBox = new QCheckBox(tr("&Multi-Sheet job"), this);

    m_copyNumberLabel->setBuddy(m_copyNumberSpinBox);

    layout->addWidget(m_copyNumberLabel);
    layout->addWidget(m_copyNumberSpinBox);
    layout->addWidget(m_multiCheckBox);
}
