#include "analyzer.h"
#include "ui_analyzer.h"

#include <QPainter>
#include <QPen>
#include <iostream>

using std::cout;
using std::endl;

void Analyzer::draw()
{
    QPixmap pixmap(QSize(imgX, imgY));
    QPainter painter;
    QPen Red(QColor(255, 0, 0), 1);
    QPen Green(QColor(0, 255, 0), 1);

    pixmap.fill();
    painter.begin(&pixmap);

    unsigned k = 0;

    for(unsigned i = 3 - 1; i <= 5 - 1; i++)
    {
        for(unsigned j = 0; j < MONTHS[i]; j++)
        {
            cout << j << "/" << i << " out: " << year[i][j].msg_out << " in: " << year[i][j].msg_in << endl;

            painter.setPen(Red);
            painter.drawRect(k * 10, imgY - year[i][j].msg_out / 100. - 5, 2, 2);

            painter.setPen(Green);
            painter.drawRect(k * 10, imgY - year[i][j].msg_in / 100. - 5, 2, 2);

            k++;
        }
    }

    painter.end();
    ui->label->setGeometry(QRect(0, 0, imgX, imgY));
    ui->label->setPixmap(pixmap);
}
