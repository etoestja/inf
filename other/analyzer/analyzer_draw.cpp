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

    QPoint prev_green, prev_red;
    QPoint curr_green, curr_red;

    for(unsigned i = 10 - 1; i <= 12 - 1; i++)
    {
        for(unsigned j = 0; j < MONTHS[i]; j++)
        {
            cout << j << "/" << i << " out: " << year[i][j].msg_out << " in: " << year[i][j].msg_in << endl;

            curr_red =   QPoint(k * 10, imgY - year[i][j].msg_out / scale - 5);
            curr_green = QPoint(k * 10,  imgY - year[i][j].msg_in / scale - 5);

            painter.setPen(Red);
            painter.drawRect(curr_red.x(), curr_red.y(), 2, 2);
            painter.drawLine(curr_red, prev_red);

            painter.setPen(Green);
            painter.drawRect(curr_green.x(), curr_green.y(), 2, 2);
            painter.drawLine(curr_green, prev_green);

            prev_green = curr_green;
            prev_red = curr_red;

            k++;
        }
    }

    painter.end();
    ui->label->setGeometry(QRect(0, 100, imgX, imgY));
    ui->label->setPixmap(pixmap);

    pixmap.detach();
}
