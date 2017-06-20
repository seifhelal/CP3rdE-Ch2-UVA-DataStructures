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
    bool operator()(string i, string j) {
        return i > j;
    }
};
int main()
{
    map <string, deque <string>> childs;
    map <string, string> parents;
    priority_queue<string, std::vector<string>, comparator> output;
    deque <string> childs_names;
    int n;
    cin >> n;
    cin.ignore();
    string  str1, str2, str3,mother_trait, father_trait, child_trait;
    for (int i=0; i < n; i++)
    {   cin >> str1 >> str2;
        if (str2=="non-existent" ||str2=="recessive" ||str2=="dominant" )
        {   parents[str1]=str2;
            output.push(str1);}
        else
        {   childs[str2].push_back(str1);
            childs_names.push_back(str2);}
    }
    bool flag=false;
    while (!flag)
    {
        flag=true;
        int y =childs_names.size();
        str1= childs_names.front();
        for (int i=0; i < y; i++)
        {   str1= childs_names.front();
            childs_names.pop_front();
            childs_names.push_back(str1);
            str2= childs[str1].back();
            childs[str1].pop_back();
            childs[str1].push_front(str2);
            str3= childs[str1].back();
            childs[str1].pop_back();
            childs[str1].push_front(str3);
            mother_trait=parents[str2];
            father_trait=parents[str3];
            if (parents[str1] !="dominant" && parents[str1] !="recessive" && parents[str1] !="non-existent")
            {   if (father_trait=="dominant" && mother_trait=="recessive")
                    child_trait="dominant";
                else if (father_trait=="recessive" && mother_trait=="dominant")
                        child_trait="dominant";
                    else if (father_trait=="dominant" && mother_trait=="dominant")
                            child_trait="dominant";
                        else if (father_trait=="recessive" && mother_trait=="recessive")
                                child_trait="recessive";
                            else if (father_trait=="non-existent" && mother_trait=="non-existent")
                                    child_trait="non-existent";
                                else if (father_trait=="recessive" && mother_trait=="non-existent")
                                        child_trait="non-existent";
                                    else if (father_trait=="non-existent" && mother_trait=="recessive")
                                            child_trait="non-existent";
                                        else if (father_trait=="dominant" && mother_trait=="non-existent")
                                                child_trait="recessive";
                                            else if (father_trait=="non-existent" && mother_trait=="dominant")
                                                    child_trait="recessive";
                                                else
                                                { flag=false;
                                                    break;}
            output.push(str1);
            parents[str1]=child_trait;}
            if (mother_trait!="dominant" && mother_trait!="recessive" && mother_trait!="non-existent" )
            {  flag=false;
                break;}
            else
                if (father_trait!="dominant" && father_trait!="recessive" && father_trait!="non-existent" )
                {   flag=false;
                    break;}}
    }
    int x=output.size();
    for (int i =0; i<x; i++)
    {   cout << output.top() << " " << parents[output.top()] << endl;
        output.pop();}
}







