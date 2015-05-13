#ifndef ANALYZER_H
#define ANALYZER_H

#include <QMainWindow>
#include <QSize>
#include <string>

using std::string;

#define NMONTHS 12
#define NDAYS 31

const int MONTHS[NMONTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct day
{
    int msg_in;
    int msg_out;
};

namespace Ui {
class Analyzer;
}

class Analyzer : public QMainWindow
{
    Q_OBJECT

public:
    explicit Analyzer(QWidget *parent = 0);
    ~Analyzer();
    string filename;

private:
    day year[NMONTHS][NDAYS];

    static const unsigned imgX = 1000;
    static const unsigned imgY = 100;

    void initArray();
    void draw();
    void readFile();
    Ui::Analyzer *ui;
};

#endif // ANALYZER_H
