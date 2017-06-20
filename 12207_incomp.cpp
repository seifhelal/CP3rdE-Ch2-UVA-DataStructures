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


using namespace std;

int main()
{
    deque <int> inps, out;
    char ch;
    int n, loop, temp = 0, outa;
    vector <int> numbers;
    int counter =1;
    bool flag=true;
    int numbers_counter=0;
    cin >> n >> loop;
    int pushes=0;
    while (n!=0 && loop!=0)
    {
        inps.clear();
        numbers.push_back(0);
        for (int i=0; i < loop; i++)
        {
            if (i!=0 && flag)
            {
                outa=inps.front();
                inps.pop_front();
                out.push_back(outa);
            }
            cout << "a7a " << endl;
            cin >> ch;
            if (ch=='N')
            {
                if (temp >= counter && !flag)
                    counter++;
                inps.push_back((counter % n));
                pushes++;
                flag=true;
                    numbers[numbers_counter]++;
                counter ++;
            }
            else
            {
                cin >> temp;
                for (int k=0; k < pushes; k++)
                {
                    if (inps.front()!=temp)
                    {
                        int y=inps.front();
                        inps.push_back(y);
                    }
                    else
                    { inps.pop_front();
                        pushes--;}
                }
                inps.push_front(temp);
                pushes++;
                flag=false;
            }
        }
            cin >> n >> loop;
            numbers_counter++;
    }

    for (int i=1; i < numbers_counter+1; i++)
    {
        cout << "case" << i <<": " <<endl;
        //cout << "kossss  " << numbers[i-1] << endl;
       // cout << out.size() << endl;
        for (int j=0; j < numbers[i-1]; j++)
        {
            cout << out.front() << endl;
            out.pop_front();
        }
    }
}




