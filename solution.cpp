#include "solution.h"
#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;


void Solution::makeNewMatrix()
{
    for(int i = 0;i < int(tmp.size());i++)
    {
      vector<int> temp1;
      for(int j = 0;j < int(tmp.size());j++)
      {
          temp1.push_back(w[tmp[i]][tmp[j]]);
      }
      result.push_back(temp1);
    }
}
string Solution::getString()
{
    string line;
    for(int i = 0;i < int(tmp.size());i++)
    {
        stringstream ss;
        ss << char(tmp[i] + 65);
        line += ss.str();
        if(i + 1 < int(tmp.size()))
        {
            line += " ";
        }
    }
    line += "\n";
    line += "\n";
    for(int i = 0;i < int(result.size());i++)
    {
        for(int j = 0;j < int(result[i].size());j++)
        {
            stringstream ss;
            ss << result[i][j];
            string l = ss.str();
            l += (j + 1 == int(result[i].size())) ? "" : " ";
            line += l;
        }
        line += "\n";
    }
    return line;
}

bool Solution::check()
{
    makeNewMatrix();
    return result == v;
}


void Solution::calculate()
{
    for(int i = 0;i < size;i++)
    {
        tmp.push_back(i);
    }
    while(next_permutation(tmp.begin(), tmp.end()))
    {
      result.clear();
      if(check())
      {
         isIsomorphic = true;
         break;
      }
    }
}

void Solution::print()
{
    for(int i = 0;i < int(tmp.size());i++)
    {
        cout << (tmp[i] + 1) << " ";
    }
    cout << endl;
    cout << endl;
    for(int i = 0;i < int(result.size());i++)
    {
        for(int j = 0;j < int(result[i].size());j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
