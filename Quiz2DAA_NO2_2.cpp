/*
    Quiz2DAA_NO2_2.cpp
    2021-11-25 Denta Bramasta
    5025201116
    first 2 
    Problems : N nails are hammered on a straight lumber. 
               Any two nails can be joined by a thread. 
               Connect some pairs of nails with a thread, 
               so that to each nail will be tied with at 
               least one thread, and the total length of 
               all threads will be minimal.
*/
#include <bits/stdc++.h>
using namespace std;
#define MAX 101

int main(){
    int a[MAX];
    int dp[MAX];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);// we sort the position Ascendingly.
    if(n == 0 || n == 1)
        cout << "0" << endl;
    else if(n == 2 || n == 3)
        cout << a[n-1] - a[0] << endl;
    // we make if else statement because if we print 1 and 3 it becomes a[n-1] - a[0];
    // same situation with 0 and 1
    else {
        dp[1]= a[1]-a[0];
        dp[2]= a[2]-a[0];

        for(int i = 3; i < n; i++) 
            dp[i] = min(dp[i-1], dp[i-2])+ a[i] - a[i-1]; // we find the minimum.
            cout << dp[n-1] << endl;
    }
    return 0;
}