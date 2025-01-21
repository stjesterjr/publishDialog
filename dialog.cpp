#include "dialog.h"

#include <QVBoxLayout>
#include <QGroupBox>

#include <QLabel>
#include <QTableWidget>
#include <QComboBox>
#include <QSpinBox>
#include <QCheckBox>
#include <QPushButton>

#include "devicewidget.h"
#include "publishlistwidget.h"
#include "toolbarwidget.h"
#include "configwidget.h"
#include "dialogcontrolswidget.h"
#include "tablewidget.h"
#include "logic.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    qDebug()<< "Dialog::Dialog(QWidget *parent)";
    m_logic = new Logic(this);

/*
    auto groupBox = new QGroupBox(tr("Layouts to plot"), this);
    groupBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    auto groupLayout = new QVBoxLayout(groupBox);

    auto topControlLayout = new QHBoxLayout();
    topControlLayout->setContentsMargins(0,0,0,0);
    topControlLayout->addWidget(new DeviceWidget(this));
    topControlLayout->addStretch(1);
    topControlLayout->addWidget(new PublishListWidget(this));
    topControlLayout->addWidget(new ToolBarWidget(this));
    groupLayout->addLayout(topControlLayout);

    auto tableView = new TableWidget(this);
    groupLayout->addWidget(tableView);

    auto bottomControl = new QWidget(this);
    bottomControl->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    auto bottomControlLayout = new QHBoxLayout(bottomControl);
    bottomControlLayout->setContentsMargins(0,0,0,0);
    bottomControlLayout->addWidget(new ConfigWidget(this));
    bottomControlLayout->addStretch(1);
    bottomControlLayout->addWidget(new DialogControlsWidget(this));

    auto main_layout = new QVBoxLayout(this);
    main_layout->addWidget(groupBox);
    main_layout->addWidget(bottomControl);
*/

    auto main_layout = new QVBoxLayout(this);
    main_layout->addWidget(createGroupBox());
    main_layout->addWidget(createBottomControls());

}

void Dialog::onControlButtonClicked(DialogActionTypes type)
{
    switch (type) {
    case DialogActionTypes::Preview:
        qDebug() << "Preview";
        break;
    case DialogActionTypes::PageSetup:
        qDebug() << "PageSetup";
        break;
    case DialogActionTypes::Publish:
        qDebug() << "Publish";
        break;
    case DialogActionTypes::Close:
        qDebug() << "Close";
        break;
    case DialogActionTypes::Help:
        qDebug() << "Help";
        break;
    default:
        qDebug() << "Default";
        break;
    }
}

void Dialog::onToolBarButtonClicked(ToolBarActionType type)
{
    switch (type) {
    case ToolBarActionType::CreateFromCurrent:
        qDebug() << "CreateFromCurrent";
        break;
    case ToolBarActionType::Create:
        qDebug() << "Create";
        break;
    case ToolBarActionType::Save:
        qDebug() << "Save";
        break;
    case ToolBarActionType::SaveAs:
        qDebug() << "SaveAs";
        break;
    case ToolBarActionType::Add:
        qDebug() << "Add";
        break;
    case ToolBarActionType::Remove:
        qDebug() << "Remove";
        break;
    case ToolBarActionType::MoveUp:
        qDebug() << "MoveUp";
        break;
    case ToolBarActionType::MoveDown:
        qDebug() << "MoveDown";
        break;
    case ToolBarActionType::DeleteEmpty:
        qDebug() << "DeleteEmpty";
        break;
    case ToolBarActionType::SetActive:
        qDebug() << "SetActive";
        break;
    default:
        qDebug() << "Default";
        break;
    }
}

Logic* Dialog::getLogic() const
{
    return m_logic;
}

QWidget *Dialog::createGroupBox()
{
    auto groupBox = new QGroupBox(tr("Layouts to plot"), this);
    groupBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    auto groupLayout = new QVBoxLayout(groupBox);

    auto topControlLayout = new QHBoxLayout();
    topControlLayout->setContentsMargins(0,0,0,0);
    topControlLayout->addWidget(new DeviceWidget(this));
    topControlLayout->addStretch(1);
    topControlLayout->addWidget(new PublishListWidget(this));
    topControlLayout->addWidget(new ToolBarWidget(this));
    groupLayout->addLayout(topControlLayout);

    auto tableView = new TableWidget(this);
    groupLayout->addWidget(tableView);

    return groupBox;
}

QWidget *Dialog::createBottomControls()
{
    auto bottomControls = new QWidget(this);
    bottomControls->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    auto bottomControlsLayout = new QHBoxLayout(bottomControls);
    bottomControlsLayout->setContentsMargins(0,0,0,0);
    bottomControlsLayout->addWidget(new ConfigWidget(this));
    bottomControlsLayout->addStretch(1);
    bottomControlsLayout->addWidget(new DialogControlsWidget(this));

    return bottomControls;
}
