#ifndef LOGIC_H
#define LOGIC_H

#include <QObject>
#include <QList>

struct LayoutInfo{
    QString m_fileName;
    QString m_name;
    QString m_plotSettingName;
    QString m_plotterName;
    QString m_paperName;
};

class Logic : public QObject
{
    Q_OBJECT
public:
    explicit Logic(QObject *parent = nullptr);
    QList<LayoutInfo> getData();

signals:
private:
    QList<LayoutInfo> m_data;
};

#endif // LOGIC_H
