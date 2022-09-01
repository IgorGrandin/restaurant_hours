#include "availablehours.h"
#include <QDebug>

availableHours::availableHours(QObject *parent)
    : QObject{parent}
{

}

void availableHours::filterHours()
{
    qDebug() << "Funcionou!!!";
}

