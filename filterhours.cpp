#include "filterhours.h"
#include <QDebug>
#include <qfile.h>
#include <QTime>
#include <QStringList>


FilterHours::FilterHours(QObject *parent)
    : QObject{parent}
    , m_avHours("00:00")
{

}

QStringList FilterHours::availableHours(){

    return m_resName;
}

void FilterHours::setAvailableHours(QStringList resTime)
{

    if(m_avHours != resTime)
    {

        m_avHours = resTime;

        QFile file("../restaurant_hours/restaurant_hours.csv");
        if (!file.open(QIODevice::ReadOnly)) {
            qDebug() << file.errorString();
        } else {
            m_resName.clear();
            while (!file.atEnd()) {
                QByteArray line = file.readLine();
                QByteArray avHours = m_avHours[0].toLocal8Bit();
                line = line.replace("\"", "").replace("\r\n","-" + avHours).replace("\n","-" + avHours);
                if(line.split('-').length() >= 3 && line.split(',').length() >= 2 ){
                    m_resName.append(line);
                }
            }

            QStringList m_resResult;

            auto pred = [](QString str) {
                QString initialTime;
                QString endTime;
                QString desTime;

                desTime = str.split("-")[str.split("-").length()-1];
                endTime = str.split("-")[str.split("-").length()-2];
                initialTime = str.split("-")[str.split("-").length()-3].split(",")[str.split(",").length()-1];

                QTime inTime = QTime::fromString(initialTime, "H:mm");
                QTime enTime = QTime::fromString(endTime, "H:mm");
                QTime deTime = QTime::fromString(desTime, "H:mm");
                bool compTime = inTime <= deTime && deTime <= enTime;
                return compTime;
            };

            std::copy_if(m_resName.begin(), m_resName.end(), std::back_inserter(m_resResult), pred);

            auto unary_op = [](QString str){
                str.remove(str.lastIndexOf("-"), 6);
                QString hourA = str.split(",")[str.split(",").length()-1];
                str.remove(str.lastIndexOf(","), 12);
                hourA = hourA.rightJustified(11, '0');
                hourA = hourA.leftJustified(20, ' ');
                return hourA.append(str);
            };

            std::transform(m_resResult.begin(), m_resResult.end(), m_resResult.begin(), unary_op);

            m_resName = m_resResult;

            emit availableHoursChanged();
        }
    }
}
