/*
    NewYearPresent.cpp
    2021-11-25 Denta Bramasta
*/

#include <bits/stdc++.h>
using namespace std;

struct dp
{
    int first, second;
};

int compare(dp p1, dp p2)
{
    int mm = min(min(p1.first, p1.second), min(p2.first, p2.second));
    if ((mm == p1.first) || (mm == p2.second))
        return 0;
    return 1;
}

int main()
{
    int n, b;
    dp santa[301], current;

    {
        int fir[301];
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> fir[i];

        for (int i = 0; i < n; i++)
            cin >> b, santa[i].first = fir[i], santa[i].second = b;
    }

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (compare(santa[i], santa[j]))
            {
                current = santa[i];
                santa[i] = santa[j];
                santa[j] = current;
            }

    int ans = 0, count = 0;
    for (int i = 0; i < n; i++)
        count += santa[i].first, ans = max(count, ans) + santa[i].second;
    cout << ans << endl;
    return 0;
}