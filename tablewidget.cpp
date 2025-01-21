#include "tablewidget.h"
#include "dialog.h"
#include "logic.h"
#include <QComboBox>
#include <QLabel>

TableWidget::TableWidget(QWidget *parent)
    : QTableWidget(parent)
{
    setColumnCount(5);
    setShowGrid(true);
    setSelectionMode(QAbstractItemView::SingleSelection);
    setSelectionBehavior(QAbstractItemView::SelectRows);
    QStringList header;
    header << "0"
           << "1"
           << "2"
           << "3"
           << "4"
           << "5";
    setHorizontalHeaderLabels(header);
    horizontalHeader()->setStretchLastSection(true);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    int i = 0;
    int c = 0;
    auto infoArray = static_cast<Dialog*>(parent)->getLogic()->getData();

    for(auto& info : infoArray)
    {
        insertRow(i);

        setItem(i, 0, new QTableWidgetItem(info.m_fileName));
        setItem(i, 1, new QTableWidgetItem(info.m_name));
        setItem(i, 2, new QTableWidgetItem(info.m_plotSettingName));

        // QComboBox* box = new QComboBox(this);
        // QStringList plotters {"plotterA", "plotterB", "plotterC", "plotterD"};
        // box->addItems(plotters);
        // setCellWidget(i, 3, box);

        auto customItem = new CustomTableWidgetItem(this);
        QStringList plotters {"plotterA", "plotterB", "plotterC", "plotterD", "plotterE"};
        customItem->addItems(plotters);
        customItem->setText("asdasdasd");

        setItem(i, 3, customItem);
        setCellWidget(i, 3, customItem);

        setItem(i, 4, new QTableWidgetItem(info.m_paperName));
    }
    setSortingEnabled(true);
}


