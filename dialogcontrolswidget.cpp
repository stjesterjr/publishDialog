#include "dialogcontrolswidget.h"
#include "dialog.h"

#include <QHBoxLayout>
#include <QPushButton>

struct ButtonInfo
{
    QString name;
    DialogActionTypes type;
};

const QVector<ButtonInfo> infoArray
{
    {
        QStringLiteral("Preview"),
        DialogActionTypes::Preview
    },
    {
        QStringLiteral("Page Setup..."),
        DialogActionTypes::PageSetup
    },
    {
        QStringLiteral("Publish"),
        DialogActionTypes::Publish
    },
    {
        QStringLiteral("Close"),
        DialogActionTypes::Close
    },
    {
        QStringLiteral("Help"),
        DialogActionTypes::Help
    },
    {
        QStringLiteral("asdasdas"),
        DialogActionTypes::Help
    }
};

DialogControlsWidget::DialogControlsWidget(QWidget *parent)
    : QWidget{parent}
{
    auto dialogControlLayout = new QHBoxLayout(this);

    /*
    m_previewButton = new QPushButton(tr("Preview..."),    this);
    m_pageSetupButton = new QPushButton(tr("Page Setup..."), this);
    m_publishButton = new QPushButton(tr("Publish"),       this);
    m_closeButton   = new QPushButton(tr("Close"),         this);
    m_helpButton    = new QPushButton(tr("Help"),          this);
    dialogControlLayout->addWidget(m_previewButton);
    dialogControlLayout->addWidget(m_pageSetupButton);
    dialogControlLayout->addWidget(m_publishButton);
    dialogControlLayout->addWidget(m_closeButton);
    dialogControlLayout->addWidget(m_helpButton);
    */

    for(auto& info : infoArray){
        auto button = new QPushButton(info.name, this);
        button->setObjectName(info.name);
        dialogControlLayout->addWidget(button);
        connect(button, &QPushButton::clicked, this, [parent, info]()->void
        {
            Dialog* typed_parent = static_cast<Dialog*>(parent);
            typed_parent->onControlButtonClicked(info.type);
        });
        this->findChild<QPushButton*>(info.name)->setEnabled(false);
    }
}
