#ifndef TOOLBARWIDGET_H
#define TOOLBARWIDGET_H

#include <QToolBar>

enum class ToolBarActionType{
    CreateFromCurrent,
    Create,
    Save,
    SaveAs,
    Add,
    Remove,
    MoveUp,
    MoveDown,
    DeleteEmpty,
    SetActive
};

class ToolBarWidget : public QToolBar
{
    Q_OBJECT
    using BaseClass = QToolBar;
public:
    explicit ToolBarWidget(QWidget* parent = nullptr);
private:
    void connectButtons();
};

#endif // TOOLBARWIDGET_H
