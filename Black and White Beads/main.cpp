//
//  main.cpp
//  Black and White Beads
//
//  Created by Denta Bramasta Hidayat on 22/09/21.
//

#include <cstdio>
#include <algorithm>
#define mod 1000000007

template <typename t>
t getNum(){
 t r=0;
 char c;
 while(1){
  c = getchar(); //getchar_unlocked();
  if(c==' ' || c=='\n') continue;
  else break;
 }
 r=c-'0';
 while(1){
  c = getchar(); //getchar_unlocked();
  if(c>='0' && c<= '9') r=10*r+c-'0';
  else break;
 }
 
 return r;
}

int dp[101][10001];

int main() {
    int pow[10001];
    pow[0] = 1;
    pow[1] = 2 % mod;
    for(int i = 2; i<=10000; i++) {
        pow[i] = (pow[i-1] * 2) % mod;
    }
    for(int i = 1; i<=100; i++) {
        for(int j = 1; j<=10000; j++) {
            if(i>j) {
                dp[i][j] = 0;
                continue;
            } else if (i == j) {
                dp[i][j] = 1;
                continue;
            }
            int temp = pow[j-(i+1)] - dp[i][j-(i+1)];
            if(temp<0) temp += mod;
            dp[i][j] = ((2*dp[i][j-1]) % mod + temp) % mod;
        }
    }
    int T, N, K;
    T=getNum<int>();
    while(T--) {
        N=getNum<int>();
        K=getNum<int>();
        int temp = pow[N-1] - dp[K][N-1];
        if(temp<0) temp += mod;
        printf("%d\n",temp);
    }
    return 0;
}
