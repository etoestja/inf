#include "analyzer.h"
#include "ui_analyzer.h"

Analyzer::Analyzer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Analyzer)
{
    ui->setupUi(this);

    filename = "../m1.txt";

    initArray();
    readFile();
    draw();
}

Analyzer::~Analyzer()
{
    delete ui;
}

void Analyzer::initArray()
{
    for(unsigned i = 0; i < NMONTHS; i++)
        for(unsigned j = 0; j < NDAYS; j++)
        {
            year[i][j].msg_in = 0;
            year[i][j].msg_out = 0;
        }
}
