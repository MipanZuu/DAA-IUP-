#include <iostream>
using namespace std;
long long precom[10000001];
long long answer[10000001];

int main() {
    for (int i = 1; i < 1000000; i++)
        {
            answer[i] = answer[i-1] + precom[i];
                for(int j = 2*i; j < 1000000; j+=i )
                {
                    precom[j] += i;
                }
            }
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        cout << answer[N] << endl;
    }
    return 0;
}
