#ifndef FILTERHOURS_H
#define FILTERHOURS_H

#include <QObject>

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
    void setAvailableHours(QStringList resName);

private:
    QStringList m_resName;

};

#endif // FILTERHOURS_H
