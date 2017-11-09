#ifndef DATA_H
#define DATA_H

#include <vector>
#include <QString>

using namespace std;

class Data
{
public:
    Data();
    ~Data();
    void read_sequence(const QString& str_nums);
    void read_numbers_from_file(const QString& filename);
    void generate_numbers(unsigned count);
    double calculate_entr(const vector<int>& numbers);

    /* public, потому что лень писать геттеры*/
    vector<int> sequence;
    vector<int> alg1;
    vector<int> alg2;
    vector<int> alg3;
    vector<int> tbl1;
    vector<int> tbl2;
    vector<int> tbl3;
};

#endif // DATA_H
