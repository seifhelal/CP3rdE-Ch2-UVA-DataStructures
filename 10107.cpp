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
    priority_queue<int> vec;
    int length, number;
    
    
    int i=0;
    while (cin >>number)
    {
        i++;
        vec.push(number);
        priority_queue<int> vec_temp=vec;

        
        if (i%2 !=0)
        {
            for (int j=0; j <(vec.size()/2); j++)
            {
                vec_temp.pop();
            }
            cout << vec_temp.top() << endl;
        }
        else
        {
            for (int j=0; j <(vec.size()/2)-1; j++)
            {
                vec_temp.pop();
            }
            length=vec_temp.top();
            vec_temp.pop();
            length+=vec_temp.top();
            cout << length/2 << endl;
        }
        
    }
}





