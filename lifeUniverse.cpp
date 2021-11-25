/*
    lifeUniverse.cpp
    2021-11-25 Denta Bramasta
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> life;
    int x = 0;
    while(x != 42)
    {
        scanf("%d",&x);
        if(x!=42)
        life.push_back(x);
    }
    for(int i=0 ; i < (signed)(life.size()) ; i++)
    {
        printf("%d\n",life.at(i));
    }
    return 0;
}