#ifndef AVAILABLEHOURS_H
#define AVAILABLEHOURS_H

#include <QObject>
#include <QList>
#include <qqml.h>

class availableHours : public QObject
{
    Q_OBJECT

public:
    explicit availableHours(QObject *parent = nullptr);


signals:
    void filterHoursChanged();

public slots:
    void filterHours();

};

#endif // AVAILABLEHOURS_H
