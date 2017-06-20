//
//  main.cpp
//  khamsa_mwah
//
//  Created by SEIF on 5/23/17.
//  Copyright © 2017 SEIF. All rights reserved.
//
#include <stdio.h>
#include <vector>
#include <iostream>
#include <cmath>
#include <string>
#include <iostream>
#include <iomanip>
#include <map>
#include <sstream>
#include <stack>
#include <deque>
#include <set>
#include <queue>
#include <list>
#include <algorithm>
#include <string.h>
#include <cstdio>
//#include "UFDS.h"

using namespace std;
typedef vector<int> vi;
#define LSOne(S) (S & (-S))

class FenwickTree {
private:
    vi ft;
    
public:
    FenwickTree() {}
    // initialization: n + 1 zeroes, ignore index 0
    FenwickTree(int n) { ft.assign(n + 1, 0); }
    
    int rsq(int b) {                                     // returns RSQ(1, b)
        int sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
        return sum;
    }
    
    int rsq(int a, int b) {                              // returns RSQ(a, b)
        return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
    }
    
    // adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
    void adjust(int k, int v) {                    // note: n = ft.size() - 1
        for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v;
    }
};


int main()
{
    int n, op, arr[100005], index, change;
    char ch;
    
    while (cin >> n >> op)
    {
        FenwickTree zeros(n), negatives(n);
    
        for (int i = 1; i <n+1; i++)
        {   cin >> arr[i];
            if (arr[i]==0)
                zeros.adjust(i, 1);
            else if (arr[i] < 0)
                negatives.adjust(i, 1);}
        for (int i=0; i < op; i++)
        {
            cin >>ch >> index >> change;
            if (ch == 'C')
            {
                if (change==0)
                {
                    if ( arr[index] !=0) zeros.adjust(index, 1);
                    if ( arr[index]  < 0) negatives.adjust(index, -1);

                }
                else if (change < 0)
                {
                    if ( arr[index] ==0)  zeros.adjust(index, -1);
                    if ( arr[index]  >= 0) negatives.adjust(index, 1);                }
                else
                {
                    if ( arr[index] == 0)  zeros.adjust(index, -1);
                    if ( arr[index]  < 0) negatives.adjust(index, -1);
                }
                arr[index]=change;
            }
            else if (ch=='P')
            {
                if (zeros.rsq(index, change) != 0) cout << 0;
                else if (negatives.rsq(index, change) % 2 != 0 )
                    cout << '-';
                else
                    cout << '+';
            }
        }
        cout << endl;
        
    }
}



/*
 
 
 
4 6
-2 6 0 -1
C 1 10
P 1 4
C 3 7
P 2 2
C 4 -5
P 1 4
5 9
1 5 -2 4 3
P 1 2
P 1 5
C 4 -5
P 1 5
P 4 5
C 3 0
P 1 5
C 4 -5
C 4 -5

 */






