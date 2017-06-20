//
//  main.cpp
//  khamsa_mwah
//
//  Created by SEIF on 5/23/17.
//  Copyright © 2017 SEIF. All rights reserved.
//

#include <vector>
#include <iostream>
#include <cmath>
#include <string>
#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <sstream>
#include <stack>
#include <deque>
#include <set>
#include <queue>

using namespace std;
struct comparator {
    bool operator()(string i, string j) {
        return i > j;
    }
};
int main()
{   deque <deque <deque<double>>> matrixes;
    deque <double> line, sizes;
    deque <deque<double>> matrix;
    int n;
    cin >> n;
    double size;
    char ch;
    double element;
    string sym_result;
    for (int i=0; i < n; i++)
    {
        cin >> ch >> ch >> size;
        sizes.push_back(size);
        for (int j=0; j <size; j++)
        {
            for (int k=0; k < size; k++)
            {
                cin >> element;
                line.push_back(element);
            }
            matrix.push_back(line);
            line.clear();
        }
        matrixes.push_back(matrix);
        matrix.clear();
    }
    for (int i=0; i < n; i++)
    {
        cout << "Test #" << i+1 << ": ";
        size=sizes.front();
        sizes.pop_front();
        sym_result="Symmetric.";
        for (int j=0; j <size; j++)
        {
            for (int k=0; k < size; k++)
            {
               if ( matrixes[i][j][k] != matrixes[i][abs(size-j-1)][abs(size-k-1)])
               {
                   sym_result="Non-symmetric.";
               }
                if ( matrixes[i][j][k]  <0 )
                    sym_result="Non-symmetric.";
            }
        }
        cout << sym_result << endl;
    }
}




