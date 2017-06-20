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
int main()
{
    deque <map <string, int>> myvec;
    map <string, int> mymap;
    deque <string> all_inp;
    deque <int> n_number;
    int temp=0;
    int sum=0;
    int n;
    int N;
    cin >>n;
    cin.ignore();
    n_number.push_back(n);
    priority_queue<int> PQ;
    string inp;
    while (n!=0)
    {
        for (int i=0; i < n; i++)
        {
            inp=" ";
            for (int i=0 ; i <5 ; i++)
            {
                cin >> N;
                PQ.push(N);
            }
            for (int i=0 ; i <5 ; i++)
            {
                inp= to_string(PQ.top())+inp;
                PQ.pop();
            }
            mymap[inp]++;
            all_inp.push_back(inp);
        }
        myvec.push_back(mymap);
        mymap.clear();
        cin >> n;
        cin.ignore();
        n_number.push_back(n);
    }
    while (!n_number.empty() && !myvec.empty())
    {
        n=n_number.front();
        n_number.pop_front();
        mymap=myvec.front();
        myvec.pop_front();
        for (int i=0; i < n; i++)
        {
            if (mymap[all_inp.front()] >=temp)
            {
                if (mymap[all_inp.front()] == temp)
                   sum=sum+mymap[all_inp.front()];
                else
                {   sum=0;
                    temp=mymap[all_inp.front()];
                    sum=sum+mymap[all_inp.front()];}
            }
            all_inp.pop_front();
        }
        cout << sum/temp << endl;
        sum=0;
        temp=0;
    }
}

