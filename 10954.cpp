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
    bool operator()(int i, int j) {
        return i > j;
    }
};
int main()
{
    priority_queue<int, std::vector<int>, comparator> myheap;
    deque <int> output;
    int n;
    cin >> n;
    int inp, sum=0, sum2=0;
    
    while (n!=0)
    {
        for (int i=0; i < n; i++)
        {
            cin >> inp;
            myheap.push(inp);
        }
        for (int i=0; i < n-1; i++)
        {
            sum=myheap.top();
            myheap.pop();
            sum=sum+myheap.top();
            myheap.pop();
            sum2= sum2+sum;
            myheap.push(sum);
            sum=0;
        }
        while (!myheap.empty())
        {
            myheap.pop();
        }
        output.push_back(sum2);
        sum2=0;
        sum=0;
        cin >>n;
        cin.ignore();
    }
    while (!output.empty())
    {
        cout << output.front() << endl;
        output.pop_front();
    }
}




