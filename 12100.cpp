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



int main()
{
    int n, num_elements, index, temp;
    cin >> n;
    
    
    for (int i=0; i < n; i++)
    {
        cin >> num_elements >> index;
        deque<int> que;
        priority_queue<int> arrange;
        for (int j=0; j < num_elements; j++)
        {
            cin >> temp;
            arrange.push(temp);
            que.push_back(temp);
            
        }
        bool flag=true;
        int counter=index, time=0 , counter2=0;
        do{
            temp= que.front();
           // cout << "front  " << que.front() << "  arra " << arrange.top() << endl;
            if ( que.front() < arrange.top())
            {
                if ( counter==0)
                    counter= num_elements-(1+counter2);
                else
                    counter--;
                
                que.pop_front();
                que.push_back(temp);
            }
            else if ( temp == arrange.top())
            {
                if ( counter==0)
                    flag=false;
                else
                    counter--;
                que.pop_front();
                counter2++;
                arrange.pop();
                time++;
            }
        }while (flag);
        cout << time << endl;
    }
    return 0;
}
/*
3
1 0
5
4 2
1 2 3 4
6 0
1 1 9 1 1 1
30 20
1 7 2 7 3 5 3 7 2 3 8 3 5 7 6 7 2 2 6 8 1 3 9 9 3 2 5 4 8 5

 
1
56 32
6 2 1 4 6 4 2 2 5 4 1 4 9 6 3 8 2 2 4 1 5 7 5 6 7 9 3 2 5 6 7 5 2 3 8 8 2 2 9 1 7 3 4 1 5 8 6 8 6 8 9 3 7 5 5 8
1
91 21
1 6 5 2 2 8 2 9 4 4 8 3 9 4 6 6 9 9 3 8 3 4 5 4 4 5 1 1 9 1 7 4 7 6 6 1 2 7 7 7 6 3 1 3 4 9 5 8 6 3 5 4 5 8 6 6 6  2 1 3 4 4 7 6 4 9 6 5 8 5 9 1 2 4 8 6 2 2 6 5 9 9 1 5 7 4 7 7 6 5 9
1
30 20
1 7 2 7 3 5 3 7 2 3 8 3 5 7 6 7 2 2 6 8 1 3 9 9 3 2 5 4 8 5
 
 
1
 91 21
 1 6 5 2 2 8 2 9 4 4 8 3 9 4 6 6 9 9 3 8 3 4 5 4 4 5 1 1 9 1 7 4 7 6 6 1 2 7 7 7 6 3 1 3 4 9 5 8 6 3 5 4 5 8 6 6 6 2 1 3 4 4 7 6 4 9 6 5 8 5 9 1 2 4 8 6 2 2 6 5 9 9 1 5 7 4 7 7 6 5 9
*/




