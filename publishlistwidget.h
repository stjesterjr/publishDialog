#ifndef PUBLISHLISTWIDGET_H
#define PUBLISHLISTWIDGET_H

#include <QWidget>

class QLabel;
class QComboBox;
class QPushButton;
class PublishListModel;

class PublishListWidget : public QWidget{
    Q_OBJECT
    using BaseClass = QWidget;
public:
    explicit PublishListWidget(QWidget *parent = nullptr);
private:
    QLabel*           m_label;
    QComboBox*        m_comboBox;
    PublishListModel* m_model;
};

#endif // PUBLISHLISTWIDGET_H
