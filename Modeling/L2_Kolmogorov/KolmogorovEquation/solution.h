#ifndef SOLUTION_H
#define SOLUTION_H
#include <vector>


class Solution
{
public:
    Solution();
    static int SolveSystem(const std::vector<std::vector<double>>& matrix, std::vector<double> &res);
};

#endif // SOLUTION_H
