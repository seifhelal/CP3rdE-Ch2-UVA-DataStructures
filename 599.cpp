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

using namespace std;

struct comparator {
    bool operator()(int i, int j) {
        return i > j;
    }
};

vector <int> verticies, connected;
vector <vector <int> > graph;
int connection_number;




bool Node_Exist(int x){
    for (int i = 0; i < verticies.size(); i++){
        if (verticies[i] == x)
            return true;
    }
    return false;
}
void dfs(int x){
    if (Node_Exist(x))
    {
        connected[x] = 1;
        connection_number++;
        for (int i = 0; i < graph[x].size(); i++)
            if (connected[graph[x][i]] == -1)
                dfs(graph[x][i]);
    }
    else return;
}




int main()
{
    int n;
    cin >> n;
    string inp;
    
    while (n--)
    {
        cin >> inp;
        graph.assign(26, vector<int>());
        while (inp[0] != '*')
        {
            int ch1=inp[1]-65, ch2=inp[3]-65;
            graph[ch1].push_back(ch2);
            graph[ch2].push_back(ch1);
            cin >> inp;
        }
        cin >> inp;
        for (int i=0; i < inp.size(); i++)
        {
            if (isalpha(inp[i]))
                verticies.push_back(inp[i]-65);
        }
        connected.assign(26, -1);
        int trees=0, acrons=0;
        
        for (int i=0; i < graph.size(); i++)
        {
            if (Node_Exist(i) && connected[i]==-1)
            {
                connection_number=0;
                dfs(i);
                if (connection_number >1)
                    trees++;
                else
                    acrons++;
            }
        }
        cout << "There are " << trees << " tree(s) and " << acrons << " acorn(s)." <<endl;
        verticies.clear();
    }
    
}





















