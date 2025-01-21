#ifndef CONFIGWIDGET_H
#define CONFIGWIDGET_H

#include <QWidget>

class QLabel;
class QCheckBox;
class QSpinBox;

class ConfigWidget : public QWidget
{
    Q_OBJECT
    using BaseClass = QWidget;
public:
    explicit ConfigWidget(QWidget *parent = nullptr);

private:
    QLabel* m_copyNumberLabel;
    QSpinBox* m_copyNumberSpinBox;
    QCheckBox* m_multiCheckBox;
};

#endif // CONFIGWIDGET_H
