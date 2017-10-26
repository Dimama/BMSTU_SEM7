#include "solution.h"

int Solution::SolveSystem(const std::vector<std::vector<double>> &matrix, std::vector<double>& res)
{
    unsigned size = matrix.size();
    std::vector<std::vector<double>> m;
    std::vector<double> b;

    for(unsigned i = 0; i < size; i++)
    {
        std::vector<double> v;
        for(unsigned j = 0; j < size; j++)
            v.push_back(0);
        m.push_back(v);
        b.push_back(0);
    }

    for(unsigned i = 0; i < size; i++)
        for (unsigned j = 0; j < size; j++)
        {
            m[i][j] += matrix[i][j];
            m[i][i] -= matrix[j][i];
        }

    for(unsigned i = 0; i < size; i++)
    {
        m[size-1][i] = 1;
        res.push_back(0);
    }
    b[size-1] = 1;

    for (unsigned i = 0; i < size - 1; i++)
    {
        unsigned imax = i;
        for (unsigned j = i; j < size; j++)
        {
            if ((m[j][i] > m[imax][i]) && (m[j][i] != 0))
                imax = j;
        }
        if (imax != i)
        {
            for (unsigned t = 0; t < size; t++)
                std::swap(m[imax][t], m[i][t]);

            std::swap(b[imax], b[i]);
        }

        for (unsigned k = i + 1; k < size; k++)
        {
            if (m[i][i] == 0)
                return -1;
            double divider = m[k][i] / m[i][i];
            for (unsigned l = i; l < size; l++)
            {
                m[k][l] = m[k][l] - m[i][l] * divider;
            }
            b[k] = b[k] - b[i] * divider;
        }
    }

    for (int i = size - 1; i >= 0; i--)
    {
        for (unsigned j = i + 1; j < size; j++)
            b[i] -= res[j] * m[i][j];
        if (m[i][i] == 0)
            return -1;
        res[i] = b[i] / m[i][i];
    }

    int sum;
    for(unsigned i = 0; i < size; i++)
    {
        sum = 0;
        for(unsigned j = 0; j < size; j++)
        {
            sum += matrix[j][i];
        }

        res[i] /= sum;
    }
    return 1;

}
