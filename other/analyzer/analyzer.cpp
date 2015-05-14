#include <QFileDialog>

#include "analyzer.h"
#include "ui_analyzer.h"

Analyzer::Analyzer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Analyzer)
{
    ui->setupUi(this);

    filename = "";
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

void Analyzer::on_pushButton_clicked()
{
    filename = QFileDialog::getOpenFileName(this,
         tr("Select message log"), "..", tr("Text files (*.txt)")).toAscii().data();

    ui->path->setText(filename.c_str());

    initArray();
    readFile();
    draw();
}

void Analyzer::on_horizontalSlider_valueChanged(int value)
{
    scale = value;
    draw();
}
