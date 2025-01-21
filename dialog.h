#ifndef DIALOG_H
#define DIALOG_H

#include <QDebug>
#include <QDialog>

enum class DialogActionTypes;
enum class ToolBarActionType;
class Logic;

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);

    void onToolBarButtonClicked(ToolBarActionType type);
    void onControlButtonClicked(DialogActionTypes type);

    Logic* getLogic() const;

private:
    QWidget* createGroupBox();
    QWidget* createBottomControls();


    Logic* m_logic;
};
#endif // DIALOG_H
