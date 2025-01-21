#ifndef TABLEWIDGET_H
#define TABLEWIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QHeaderView>
#include <QComboBox>

class CustomTableWidgetItem : public QComboBox, public QTableWidgetItem
{
    Q_OBJECT
    using BaseClass_A = QComboBox;
    using BaseClass_B = QTableWidgetItem;
public:
    CustomTableWidgetItem( QWidget* parent )
        : BaseClass_A( parent )
    {
    }
    CustomTableWidgetItem(const QString txt = QString("empty"))
        : BaseClass_B(txt)
    {
    }

    bool operator <(const QTableWidgetItem& other) const
    {
        if(other.column() == 3 /* progress bar */) {
            const BaseClass_A *p = dynamic_cast<const BaseClass_A*>(&other);
            if(p != nullptr) {
                if(this->currentText() < p->currentText())
                    return true;
            }
        }

        return BaseClass_B::operator <(other);
    }
};

class TableWidget : public QTableWidget
{
    Q_OBJECT
public:
    TableWidget(QWidget *parent = nullptr);
};

#endif // TABLEWIDGET_H
