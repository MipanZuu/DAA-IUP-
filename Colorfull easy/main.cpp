//
//  main.cpp
//  Colorfull easy
//
//  Created by Denta Bramasta Hidayat on 22/09/21.
//

#include <cstdio>
#include <string>
using namespace std;
typedef long long ll;
const ll mod=1000000007;

ll modStr (string num, ll modulo) {
    ll res = 0;
    for(int i = 0; i < num.length(); i++)
        res = (res*10 + (ll)num[i] - '0') % modulo;
        
        return res;
    
}

ll modex (ll b, ll e) {
    ll r=1;
    b = b % mod;
    while(e>0) {
        if((e&1)==1){
            r=(r*b)%mod;
        }
        e >>=1;
        b=(b*b)%mod;
    }
    return (ll)r;
}

int main() {
    int t;
        scanf("%d",&t);
    while(t--) {
        char a[1000], c[1000];
        scanf("%s %s", &a, &c);
        ll n = modStr(a, mod-1);
        ll k = modStr(c, mod);
        ll func;
        
        if(n%2==1) { //ganjil
            func = modex(k-1, n) - (k-1);
            func += mod;
            func %= mod;
            printf("%lld\n", func);
        }
        else { //genap
            func = modex(k-1, n) + (k-1);
            func += mod;
            func %= mod;
            printf("%lld\n", func);
        }
        
    }
    return 0;
}
