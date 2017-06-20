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
#include <vector>
#include <sstream>
#include <stack>
#include <deque>
#include <set>
#include <queue>
#include <list>
#include<stdio.h>
#include <set>
#include <cstdio>


using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int>   vi;

vector<vi> sets;
int parent[10000];
int RANK [10000];

void make_sets(int number_of_elements)
{
    int i;
    for(i = 0; i < number_of_elements; i++)
    {
        parent[i] = i;
        RANK[i] = 1;
    }
}

int find_set(int element)
{
    if(element != parent[element])
        parent[element] = find_set(parent[element]);
    return parent[element];
}

void set_union(int x, int y)
{
    int rx, ry;
    rx = find_set(x);
    ry = find_set(y);
    if(rx == ry)
        return;
    if(RANK[rx] > RANK[ry])
    {
        RANK[rx] += RANK[ry];
        parent[ry] = rx;
    }
    else
    {
        RANK[ry] += RANK[rx];
        parent[rx] = ry;
    }
}

void read_graph()
{
    string str;
    stringstream ss;
    int people = 0, tree = 0, data;
    
    while(getline(cin,str))
    {   int flag = 0;
        if(str.size() == 0)
            return;
        ss<<str;
        while(ss>>data)
        {
            if(!flag)
            {
                people = data;
                flag = 1;
            }
            else
                tree = data;
        }
        ss.clear();
        sets[people-1].insert(tree-1);
    }
}

int main()
{
    int n=0, p, t;
    cin >> n;
    string empty;
    getline(cin, empty);
    getline(cin, empty);
    
    while (n--)
    {
        cin >> p >> t;
        make_sets(p);

        sets.assign(p, vi());
        getline(cin, empty);
        string str;
        stringstream ss;
        int pep=0, tr=0;
        while (getline (cin, str ))
        {
            if (str.size()==0)
            {break;
            }
            ss << str;
            while (ss >> pep)
            {   ss>> tr;
            }
            sets[pep-1].insert(tr-1);
            ss.clear();
        }

        for (int i=0; i < sets.size(); i++)
        {
            for (int j=i+1; j < sets.size(); j++)
            {
                if (sets[i]==sets[j])
                    set_union(parent[i], parent[j]);
                
            }
        }
        for(int g=0; g<p; g++)
            parent[g] = find_set(g);
        
        set<int>answer;
        for(int h=0; h<p; h++)
            answer.insert(parent[h]);
        
        printf("%d\n",answer.size());
        if(n)
            printf("\n");
    }
    
    
}














