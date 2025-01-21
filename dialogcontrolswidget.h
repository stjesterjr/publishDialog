#ifndef DIALOGCONTROLSWIDGET_H
#define DIALOGCONTROLSWIDGET_H

#include <QWidget>

enum class DialogActionTypes{
    Preview,
    PageSetup,
    Publish,
    Close,
    Help
};

class QPushButton;

class DialogControlsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DialogControlsWidget(QWidget *parent = nullptr);

private:
    QPushButton* m_previewButton;
    QPushButton* m_pageSetupButton;
    QPushButton* m_publishButton;
    QPushButton* m_closeButton;
    QPushButton* m_helpButton;
};

#endif // DIALOGCONTROLSWIDGET_H
