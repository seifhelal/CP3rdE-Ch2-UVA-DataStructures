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
#include <sstream>      // std::stringstream
#include "DEQ.hpp"
#include "DEQ.cpp"
using namespace std;

struct data{
    int counter=0;
    string NAME;
    int B, size, D;
    DEQ <int> pairs;
    DEQ <int> Is;

};

void catchint1(string & name, map <string, data> &mymap){
    string namestring;
    int temp;
    stringstream ss(name);
    ss >> namestring;
    ss >> mymap[name].B >> mymap[name].size>>mymap[name].D;
    cout <<namestring << mymap[name].B << mymap[name].size<< mymap[name].D << endl;
    mymap[namestring].NAME=namestring;
    for (int i=0; i <mymap[name].D*2; i++)
    {
        ss>>temp;
        mymap[namestring].pairs.add_front(temp);
    }
}

void catchint2(string & name, map <string, data> &mymap, string arr)
{
    string namestring;
    int temp;
    stringstream ss(name);
    ss >>namestring;
    arr=namestring;
    for (int i=0; i < mymap[namestring].D; i++)
    {
        ss>>temp;
        mymap[namestring].Is.add_front(temp);
        mymap[namestring].counter++;
    }
}


int main()
{
    int n,r, tempL, tempM, c0, index;
    string name, namestring;
    cin >> n;
    cin >>r;
    string arr[r];
    int address=0;
    map <string, data> mymap;
    for (int i=0; i < n; i++)
    {
        getline (cin, name);
        cin.ignore();
        catchint1(name,mymap);
    }

    for (int i=0; i < r; i++)
    {
        getline (cin, name);
        cin.ignore();
        catchint2(name,mymap, arr[i]);
        
    }
   
    for (int i=0; i < r; i++)
    {
        int CD= mymap[arr[i]].size;
        int Cd;
        int  C0= mymap[arr[i]].B -CD;
        
        mymap[arr[i]].Is.remove_front(index);
        mymap[arr[i]].Is.add_rear(index);
        
        address=index*CD;
        for (int j=0; j < mymap[arr[i]].size -1; j++)
        {
            cout << ',';
            mymap[arr[i]].pairs.remove_front(tempM);
            mymap[arr[i]].pairs.add_rear(tempM);
            mymap[arr[i]].pairs.remove_front(tempL);
            mymap[arr[i]].pairs.add_rear(tempL);
            Cd=CD*(tempM-tempL+1);
            
            mymap[arr[i]].Is.remove_front(index);
            mymap[arr[i]].Is.add_rear(index);
            address+=index*Cd;
            cout << ' '<<index;

            mymap[arr[i]].pairs.remove_front(tempM);
            mymap[arr[i]].pairs.add_rear(tempM);
            mymap[arr[i]].pairs.remove_front(tempL);
            mymap[arr[i]].pairs.add_rear(tempL);

            C0=C0-(Cd*tempL);
            CD=Cd;
        }
        cout << arr[i] << '[';
        for (int k=0; k < mymap[arr[i]].size; k++)
        {
            mymap[arr[i]].Is.remove_rear(index);
            cout << index << ' ,';
        }
        cout << "] = " << endl;
        

    }
    
}
/*
3 4
ONE 1500 2 2 0 3 1 5
TWO 2000 4 3 1 4 0 5 5 10
THREE 3000 1 1 1 9
ONE 2 4
THREE 7
TWO 2 0 6
TWO 3 3 9
*/


