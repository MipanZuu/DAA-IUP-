/*
    Quiz2DAA_NO2_1.cpp
    2021-11-25 Denta Bramasta
    5025201116
    first 2 
    Problems :
                Vasya is going to hike with fellow programmers 
                and decided to take a responsible approach to the 
                choice of what he will take with him. Vasya has n 
                things that he could take with him in his knapsack. 
                Every thing weighs 1 kilogram. Things have different "
                usefulness" for Vasya. The hiking is going to be very long, 
                so Vasya would like to carry a knapsack of weight no more 
                than w kilo.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int w,  n;
    vector<int> cost;
	cin >> w >> n;
	cost.assign(n, 0); 
    // we assign the n to the cost as 0
    int i;
	for (i = 0; i < n; i++) 
    cin >> cost[i];
	sort(cost.begin(), cost.end(), greater<int>());
    // we sort from begin until the end and the greatest to the lowest.
    int s;
	for (s = i = 0; i < min(w, n); i++)// we looping until the minimum of w and n
    s += cost[i];
	cout << s << endl;
	return 0;
}