#include "data.h"
#include <QDebug>
#include <fstream>
#include <sstream>
#include <QRegularExpression>
#include <map>
#include <math.h>

typedef std::pair<int, int> Pair;

Data::Data()
{

}

Data::~Data()
{
    this->sequence.clear();
    this->alg1.clear();
    this->alg2.clear();
    this->alg3.clear();
    this->tbl1.clear();
    this->tbl2.clear();
    this->tbl3.clear();
}

void Data::read_sequence(const QString &str_nums)
{
    this->sequence.clear();
    QStringList nums = str_nums.split(QRegularExpression(" "));
    for(QString num: nums)
    {
        this->sequence.push_back(num.toInt());
    }
}

void Data::read_numbers_from_file(const QString &filename)
{
    this->tbl1.clear();
    this->tbl2.clear();
    this->tbl3.clear();

    ifstream fin(filename.toStdString());
    if (!fin)
    {
        qDebug() << "Error: File is not opened!";
        return;
    }


    string num;
    while (fin >> num)
    {
        int n = QString(num.data()).toInt();
        if (n <= 9)
            this->tbl1.push_back(n);
        if ((n > 9) && (n <= 99))
            this->tbl2.push_back(n);
        if ((n > 99) && (n <= 999))
            this->tbl3.push_back(n);
    }

}

void Data::generate_numbers(unsigned count)
{
    this->alg1.clear();
    this->alg2.clear();
    this->alg3.clear();

    for(unsigned i = 0; i < count; i++)
    {
        this->alg1.push_back(rand() % 10);
        this->alg2.push_back(rand() % 90 + 10);
        this->alg3.push_back(rand() % 900 + 100);
    }
}

double Data::calculate_entr(const vector<int> &numbers)
{
    std::map<int, int> pairs;

    for(int num: numbers)
    {
        if(!pairs.count(num))
        {
            pairs.insert(Pair(num, 0));
        }
        pairs[num] += 1;
    }

    double en = 0.0;
    for(Pair pair: pairs)
    {
        double pi = (double) pair.second / numbers.size();
        en -= pi * log(pi) / log(numbers.size());
    }
    qDebug() << en;
    return en;
}
