#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <string>

class Solution
{
public:
    Solution(std::vector< std::vector<int> > aV, std::vector< std::vector<int> > aW, int aSize)
       {
        v = aV;
        w = aW;
        size = aSize;
        isIsomorphic = false;
    };
    void calculate();
    bool check();
    void makeNewMatrix();
    void print();
    std::string getString();
    bool isIsomorphism()
    {
        return isIsomorphic;
    }

private:
    int factorial(int n);
    int size;
    bool isIsomorphic;
    std::vector< std::vector<int> > v;
    std::vector< std::vector<int> > w;
    std::vector<int> tmp;
    std::vector< std::vector<int> > result;

};

#endif // SOLUTION_H
