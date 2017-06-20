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
    int arr [1000][1000];
    int numbers[1000];
    int mins[1000];
    int n;
    int min= 26;
    string line;
    cin>> n;
    cin.ignore();
    int c=0;
    while (n!=0)
    {for (int i=0; i < n; i++)
    {
        arr[c][i]=0;
        cin.clear();
        cin.sync();
        getline(cin, line);
        for (int j=0; j < 25; j++)
        {       if (line[j]!='X')
            arr[c][i]++;}
        if (arr[c][i] < min)
            min=arr[c][i];}
        numbers[c]=n;
        cin >> n;
        cin.ignore();
        mins[c]=min;
        c++;
        min= 26;}
    int sum=0;
    for (int i=0; i < c; i++)
    {sum=0;
        for (int j=0; j < numbers[i]; j++)
            sum+=arr[i][j]- mins[i];
        cout << sum << endl;}
}




