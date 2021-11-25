
// masih error

#include <bits/stdc++.h>
using namespace std;
int wt[100001];
int val[100001];

int knapSack(int W, int wt[], int val[], int n)
{
    // making and initializing dp array
    int dp[W + 1];
    memset(dp, 0, sizeof(dp));
 
    for (int i = 1; i < n + 1; i++) {
        for (int w = W; w >= 0; w--) {
 
            if (wt[i - 1] <= w)
                // finding the maximum value
                dp[w] = max(dp[w],
                            dp[w - wt[i - 1]] + val[i - 1]);
        }
    }
    return dp[W]; // returning the maximum value of knapsack
}
 
int main()
{
    // int val[] = { 10, 15, 40 };
    // int wt[] = { 1, 2, 3 };
    // int W = 6;
    int a, b;
    cin >> a >> b;
    for (int i = 0; i < b; i++)
    cin >> wt[i] >> val[i];

    int n = sizeof(val) / sizeof(val[0]);
    cout << knapSack(a, wt, val, n) << endl;
    return 0;
}