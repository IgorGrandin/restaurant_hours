#ifndef FILTERHOURS_H
#define FILTERHOURS_H

#include <QObject>
//#include <qqml.h>

class FilterHours : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList availableHours READ availableHours WRITE setAvailableHours NOTIFY availableHoursChanged)

public:
    explicit FilterHours(QObject *parent = nullptr);
    QStringList availableHours();
    QStringList m_avHours;

signals:
    void availableHoursChanged();

public slots:
    void setAvailableHours(QStringList resName);//QString docName, QString hour, QStringList restName);

private:
    QStringList m_resName;

};

#endif // FILTERHOURS_H
