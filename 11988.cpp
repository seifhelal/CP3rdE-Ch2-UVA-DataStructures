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
#include <list>

using namespace std;


int main()
{
    string inp, temp;
    list <char> out;
    list<char>::iterator it;
    
    while (getline(cin, inp))
    {
        out.clear();
        it=out.begin();
        for (int i=0; i < inp.size(); i++)
        {
            if (inp[i] == '[')
                it=out.begin();
            else
                if(inp[i] == ']')
                    it=out.end();
            if (inp[i] != '[' && inp[i] != ']')
                out.insert(it, inp[i]);
        }
        while (!out.empty())
        {
            cout << out.front();
            out.pop_front();
        }
        cout << endl;
    }
    
}




