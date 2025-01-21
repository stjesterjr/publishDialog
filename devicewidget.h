#ifndef DEVICEWIDGET_H
#define DEVICEWIDGET_H

#include <QWidget>

class QLabel;
class QComboBox;
class QPushButton;
class DeviceModel;

class DeviceWidget : public QWidget{
    Q_OBJECT
    using BaseClass = QWidget;
public:
    explicit DeviceWidget(QWidget *parent = nullptr);
private:
    QLabel*      m_label;
    QComboBox*   m_comboBox;
    QPushButton* m_button;
    DeviceModel* m_model;
};


#endif // DEVICEWIDGET_H
