#include "logic.h"

#include <QDebug>

Logic::Logic(QObject *parent)
    : QObject{parent}
{
    qDebug() << "Logic::Logic(QObject *parent)";
    for(int i = 0; i < 5; ++i){
        LayoutInfo info{
            QString("filename %1").arg(i),
            QString("name %1").arg(i),
            QString("setting %1").arg(i),
            QString("plotter %1").arg(i),
            QString("paper %1").arg(i)
        };

        m_data.push_back(info);
    }

}

QList<LayoutInfo> Logic::getData(){
    return m_data;
}
