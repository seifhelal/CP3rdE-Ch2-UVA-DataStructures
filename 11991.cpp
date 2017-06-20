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


int main()
{
    map <int , vector <int> > mymap;
    string str;
    stringstream ss;
    int num_elements, num_quiries, number, occ;
    while (getline (cin, str))
    {
        ss << str;
        ss >> num_elements >> num_quiries;
        //cout << "number " << num_elements << "  qur  " << num_quiries << endl;
        ss.clear();
        for (int i=1; i < num_elements+1; i++)
        {   cin >> number;
            mymap[number].push_back(i);}
        for ( int i =0; i < num_quiries; i++)
        {   cin >> occ >> number;
            if (mymap[number].size() >= occ)
                cout << mymap[number][occ-1] << endl;
            else
                cout << 0 << endl;}
        mymap.clear();
        cin.ignore();
    }
}



/*
 
 
8 4
1 3 2 2 4 3 2 1
1 3
2 4
3 2
4 2
17 36
90 90 67 67 90 90 90 90 90 90 90 90 67 90 90 90 90
3 67
1 67
5 90
3 67
2 67
1 67
6 90
3 90
7 90
17 90
6 90
3 67
6 90
10 90
2 67
3 90
3 67
3 67
3 67
4 90
3 67
14 90
3 67
14 90
2 67
1 67
11 90
3 90
12 90
3 67
2 67
1 67
1 67
2 67
2 67
1 67
 
 
 */






