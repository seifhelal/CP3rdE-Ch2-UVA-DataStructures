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
    int n;
    cin >> n;
    cin.ignore();
    int sum=0;
    int height;
    int moves [1000];
    int c=0;
    while (n!=0)
    {
        int arr[n];
        for (int i=0; i < n; i++)
        {
            cin >> arr[i];
            sum+=arr[i];
        }
        height=sum/n;
        moves[c]=0;
        for (int i=0; i <n; i++ )
        {
            if (arr[i]< height)
                moves[c]+=(height-arr[i]);
        }
        c++;
        sum=0;
        cin >> n;
        cin.ignore();
    }
    for (int i=0; i<c; i++)
        cout <<"Set #" << i+1 << endl <<"The minimum number of moves is "<< moves[i] << '.'<< endl << endl;
}




