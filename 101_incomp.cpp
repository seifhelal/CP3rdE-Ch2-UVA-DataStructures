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
int main()
{
    string operation1, operation2;
    int block1, block2, n;
    cin >> n;
    map <int, pair <int, deque<int> > > blocks;
    deque <int> block;
    bool flag=true, FLAG=true;
    
    for (int i=0; i < n; i++)
    {
        blocks[i].second.push_back(i);
        blocks[i].first=i;
    }
    
    while(FLAG)
    {
        cin >> operation1;
        if (operation1=="quit")
        {
            FLAG=false;
            break;
        }
        cin >> block1 >> operation2 >> block2;
        cin.ignore();
        if (operation1=="move")
        {
            if (operation2== "onto")
            {
                
                while (flag&& ! blocks[blocks[block1].first].second.empty())
                {
                    if (blocks[blocks[block1].first].second.front() != block1)
                    {
                        cout << "a7a";
                        blocks[blocks[blocks[block1].first].second.front()].second.push_back(blocks[blocks[block1].first].second.front());
                        blocks[blocks[blocks[block1].first].second.front()].first=blocks[blocks[block1].first].second.front();
                        cout << operation1 << block1 << operation2<<block2 <<"  "<<blocks[blocks[blocks[block1].first].second.front()].first << endl;
                        blocks[blocks[block1].first].second.pop_front();
                    }
                    else
                        flag=false;
                }
                flag=true;
                while (flag&& !blocks[blocks[block2].first].second.empty())
                {
                    if (blocks[blocks[block2].first].second.front() != block2)
                    {
                    blocks[blocks[blocks[block2].first].second.front()].second.push_back(blocks[blocks[block2].first].second.front());
                    blocks[blocks[blocks[block2].first].second.front()].first=blocks[blocks[block2].first].second.front();
                        cout << operation1 << block1 << operation2<<block2 <<"  "<<blocks[blocks[blocks[block2].first].second.front()].first << endl;
                    blocks[blocks[block2].first].second.pop_front();
                    }
                    else
                        flag=false;
                }
                flag=true;
                blocks[blocks[block2].first].second.push_front(blocks[blocks[block1].first].second.front());
                blocks[blocks[block1].first].second.pop_front();
                blocks[block1].first=blocks[blocks[block2].first].first;
            }
            else
            {
                while (flag && !blocks[blocks[block1].first].second.empty())
                {
                    if (blocks[blocks[block1].first].second.front() != block1)
                    {
                        blocks[blocks[blocks[block1].first].second.front()].second.push_back(blocks[blocks[block1].first].second.front());
                        blocks[blocks[blocks[block1].first].second.front()].first=blocks[blocks[block1].first].second.front();
                        cout << operation1 << block1 << operation2<<block2 <<"  "<<blocks[blocks[blocks[block1].first].second.front()].first << endl;
                        blocks[blocks[block1].first].second.pop_front();
                    }
                    else
                        flag=false;
                }
                flag=true;
                blocks[blocks[block2].first].second.push_front(blocks[blocks[block1].first].second.front());
                blocks[blocks[block1].first].second.pop_front();
                blocks[block1].first=blocks[blocks[block2].first].first;
            }
        }
        else if (operation1== "pile")
        {
            if (operation2== "onto")
            {
                while (flag &&! blocks[blocks[block2].first].second.empty())
                {
                    if (blocks[blocks[block2].first].second.front() != block2)
                    {
                        blocks[blocks[blocks[block2].first].second.front()].second.push_back(blocks[blocks[block2].first].second.front());
                        blocks[blocks[blocks[block2].first].second.front()].first=blocks[blocks[blocks[block2].first].second.front()].first;
                        blocks[blocks[block2].first].second.pop_front();
                    }
                    else flag=false;
                }
                flag=true;
                while (flag && !blocks[blocks[block1].first].second.empty())
                {
                    if (blocks[blocks[block1].first].second.front() != block1)
                    {
                        block.push_front(blocks[blocks[block1].first].second.front());
                        blocks[blocks[block1].first].second.pop_front();
                    }
                    else
                    {
                        flag=false;
                        block.push_front(blocks[blocks[block1].first].second.front());
                        blocks[blocks[block1].first].second.pop_front();
                    }
                }
                flag=true;
                while (!block.empty())
                {
                    blocks[blocks[block2].first].second.push_front(block.front());
                    blocks[block.front()].first=blocks[blocks[block2].first].first;
                    block.pop_front();
                }
                block.clear();
            }
            else
            {    /// over
                while (flag && !blocks[blocks[block1].first].second.empty())
                {
                    if (blocks[blocks[block1].first].second.front() != block1)
                    {
                        block.push_front(blocks[blocks[block1].first].second.front());
                        blocks[blocks[block1].first].second.pop_front();
                    }
                    else
                    {
                        flag=false;
                        block.push_front(blocks[blocks[block1].first].second.front());
                        blocks[blocks[block1].first].second.pop_front();
                    }
                }
                flag=true;
                while (!block.empty())
                {
                    blocks[blocks[block2].first].second.push_front(block.front());
                    blocks[block.front()].first=blocks[blocks[block2].first].first;
                    block.pop_front();
                }
                block.clear();
            }
        }
    }
    for (int i=0; i < n; i++)
    {
        cout << i << ": ";
        while (!blocks[i].second.empty())
        {
            cout <<blocks[i].second.back() << " ";
            blocks[i].second.pop_back();
        }
        cout << endl;
    }
}
/*
10
move 9 onto 1
move 8 over 1
move 7 over 1
move 6 over 1
move 2 over 1
move 4 over 9
quit
 
 
10
move 9 over 1
move 8 over 1
move 7 over 1
move 6 over 1
pile 8 over 6
pile 8 over 5
move 2 over 1
move 4 over 9
quit 
 
 
21
move 2 onto 1
move 3 onto 2
move 4 onto 3
move 5 over 1
pile 1 over 10
move 9 over 8
move 11 over 8
pile 3 over 8
pile 8 over 3
move 20 over 19
pile 19 over 18
pile 18 onto 15
move 15 over 3
pile 20 onto 19
pile 19 onto 18
pile 18 over 17
quit
 
 
 
 
24
move 2 over 8
pile 11 onto 18
pile 13 onto 15
pile 22 over 15
move 17 over 11
move 12 over 7
pile 4 onto 17
move 19 over 22
pile 11 over 18
move 21 onto 4
pile 23 onto 9
pile 13 over 15
move 6 over 16
move 21 over 12
move 9 onto 5
move 21 onto 11
quit
 
 
 
 
24
move 2 over 8
pile 11 onto 18
pile 13 onto 15
pile 22 over 15
move 17 over 11
move 12 over 7
pile 4 onto 17
move 19 over 22
pile 11 over 18
move 21 onto 4
pile 23 onto 9
pile 13 over 15
move 6 over 16
move 21 over 12
move 9 onto 5
move 21 onto 11
move 14 onto 7
pile 18 over 9
pile 1 over 12
move 3 over 13
pile 7 onto 4
pile 14 over 1
move 19 over 1
pile 9 over 20
pile 22 onto 17
pile 2 over 17
move 11 over 1
move 19 onto 15
move 6 onto 15
move 6 onto 22
pile 17 onto 9
move 11 onto 22
pile 19 onto 6
move 7 onto 3
pile 20 onto 3
move 15 onto 8
move 18 onto 21
move 21 onto 21
pile 14 over 4
pile 18 over 16
move 18 over 12
pile 9 onto 2
pile 12 onto 7
move 4 onto 8
pile 18 onto 10
quit
*/







