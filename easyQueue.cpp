/*
    easyQueue.cpp
    2021-11-21 Denta Bramasta
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<long long>myQueue;
    long long t, input, n;
    cin >> t;
    while(t--){
        cin >> input;
        if (input == 1)
        {
            cin >> n;
            myQueue.push(n);
        }
        else if (input == 2){
            myQueue.pop();
        }
        else if (input == 3) {
            if (myQueue.empty())
            {
                cout << "Empty!" << endl;
            }
            else
                cout << myQueue.front() << endl;
        }  
    }
    return 0;
}