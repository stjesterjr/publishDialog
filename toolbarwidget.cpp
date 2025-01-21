#include "toolbarwidget.h"

#include "dialog.h"

#include <QAction>
#include <QVector>

struct ActionInfo
{
    QString name;
    QString iconPath;
    QString toolTip;
    ToolBarActionType type;
};

const QVector<ActionInfo> m_infoStrings
{
    {
        QStringLiteral("create_list_current_doc"),
        QStringLiteral(":/res/create_list_current_doc.png"),
        QStringLiteral("Make Sheet List from Current Document\nMake Sheet List from Current Document"),
        ToolBarActionType::CreateFromCurrent
    },
    {
        QStringLiteral("create_list"),
        QStringLiteral(":/res/add_custom_paper_size.png"),
        QStringLiteral("New Sheet List\nNew Sheet List"),
        ToolBarActionType::Create
    },
    {
        QStringLiteral("save_list"),
        QStringLiteral(":/res/save_list.png"),
        QStringLiteral("Save Sheet List\nSave Sheet List"),
        ToolBarActionType::Save
    },
    {
        QStringLiteral("save_list_as"),
        QStringLiteral(":/res/save_list_as.png"),
        QStringLiteral("Save Sheet List As\nSave Sheet List As"),
        ToolBarActionType::SaveAs
    },
    {
        QStringLiteral("add_page"),
        QStringLiteral(":/res/add_page.png"),
        QStringLiteral("Add Sheet to List\nAdd Sheet to List"),
        ToolBarActionType::Add
    },
    {
        QStringLiteral("up_page"),
        QStringLiteral(":/res/up_page.png"),
        QStringLiteral("Move Up\nMove Up"),
        ToolBarActionType::MoveUp
    },
    {
        QStringLiteral("down_page"),
        QStringLiteral(":/res/down_page.png"),
        QStringLiteral("Move Down\nMove Down"),
        ToolBarActionType::MoveDown
    },
    {
        QStringLiteral("remove_page"),
        QStringLiteral(":/res/remove_page.png"),
        QStringLiteral("Remove from List\nRemove from List"),
        ToolBarActionType::Remove
    },
    {
        QStringLiteral("unconfigured_plotter"),
        QStringLiteral(":/res/unconfigured_plotter.png"),
        QStringLiteral("Delete All Items with Empty Plotter\nDelete All Items with Empty Plotter"),
        ToolBarActionType::DeleteEmpty
    },
    {
        QStringLiteral("print"),
        QStringLiteral(":/res/on_print.png"),
        QStringLiteral("Switch All Items to Print State\nSwitch All Items to Print State"),
        ToolBarActionType::SetActive
    }
};

ToolBarWidget::ToolBarWidget(QWidget* parent)
    : BaseClass(parent)
{
    for(const ActionInfo& info : m_infoStrings){
        auto action = new QAction(this);

        action->setObjectName(info.name);
        action->setIcon(QIcon(info.iconPath));
        action->setText      (info.name);
        action->setToolTip   (info.toolTip);
        this->addAction(action);
        connect(action, &QAction::triggered, this, [parent, info]()->void
        {
            Dialog* typed_parent = static_cast<Dialog*>(parent);
            typed_parent->onToolBarButtonClicked(info.type);
        });
    }
}

void ToolBarWidget::connectButtons() {

}
