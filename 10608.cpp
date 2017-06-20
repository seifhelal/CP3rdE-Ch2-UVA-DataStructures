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
#include <vector>
#include <sstream>
#include <stack>
#include <deque>
#include <set>
#include <queue>
#include <list>
#include<stdio.h>
#include <set>
#include <iostream>
#include <algorithm>
#include <set>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <cstdio>
//#include "UFDS.h"

using namespace std;

class UFDS {
private:
    vector<int> p, rank, setSizes;
    int numSets;
public:
    UFDS(int N) {
        numSets = N;
        rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; i++)
            p[i] = i;
        setSizes.assign(N, 1);
    }
    int findSet(int i) {
        return (p[i] == i) ? i : p[i] = findSet(p[i]);
    }
    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) {
                setSizes[findSet(x)] += setSizes[findSet(y)];
                p[y] = x;
            }
            else {
                setSizes[findSet(y)] += setSizes[findSet(x)];
                p[x] = y;
                if (rank[x] == rank[y])
                    rank[y]++;
            }
            numSets--;
        }
    }
    int setSize(int i) {
        return setSizes[findSet(i)];
    }
    int numDisjointSets() {
        return numSets;
    }
};



int arr[100005];

int main()
{
    int test_cases=0, num_people, num_pairs, cit1=0, cit2=0;
    string empty, str;
    stringstream ss;
    cin >> test_cases;
    for (int i=0; i < test_cases; i++)
    {
        cin >> num_people >> num_pairs;
        UFDS sett(num_people);
        cit1=0, cit2=0;
        for (int j=0; j < num_pairs; j++)
        {
            cin >> cit1;
            cin >>cit2 ;
            sett.unionSet(cit1-1, cit2-1);
        }
        int temp=0;
        fill (arr, arr+num_people, 0);
        for (int i=0 ; i < num_people; i++)
            arr[sett.findSet(i)]++;
        for (int j=0; j < num_people; j++)
            if (temp < arr[j])
                temp=arr[j];
              cout << temp << endl;
    }
}
/*

2
3 2
1 2
2 3
10 12
1 2
3 1
3 4
5 4
3 5
4 6
5 2
2 1
7 1
1 2
9 10
8 9

*/









