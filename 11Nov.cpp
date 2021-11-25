/*
    11Nov.cpp
    2021-11-11 Denta Bramasta
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int L,N;
    pair<int, int> gasStation[10000];
    
    while(true){
        scanf("%d %d",&L,&N);
        
        if(L == 0) break;

        for(int i = 0,x,r;i < N;++i){
            scanf("%d %d",&x,&r);
            gasStation[i] = make_pair(x - r,x + r);
            // printf("[%d, %d] ", gasStation[i-1].first, gasStation[i+1].second);
        }
        sort(gasStation, gasStation + N);
        int pos = 0, aux, i = 0,ans = N;
        
        while(pos < L){
            aux = pos;
            
            while(i < N && gasStation[i].first <= pos)
                aux = max(aux,gasStation[i++].second);
            
            if(aux == pos) break;
    
            pos = aux;
            --ans;
        }
        
        printf("%d\n",pos < L? -1 : ans);
    }
    
    return 0;
}