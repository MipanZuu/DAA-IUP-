//https://tlx.toki.id/courses/competitive/chapters/07/problems/B
//0-1 Knapsack Dynamic Programming
#include <stdio.h>

#define max(x, y) ((x < y) ? y : x)
/*
test case:
8 4
2 1
3 2
4 5
5 6

11 3
10 30
6 17
5 14

30 4
11 2
12 2
13 2
14 2

30 4
10 1
15 2
25 3
20 2

14 5
5 6
4 5
3 4
7 6
4 4
*/

int main() {
    int G, N;   //G:max weight, N: number of elements
    scanf("%d %d", &G, &N);
    int Weight[N+1], Price[N+1];    //wt: weight, p:price
    int dp[N+1][G+1];   //memoization
    Weight[0]=Price[0]=0;   //starting from zero
    for(int c=1;c<=N;c++)
        scanf("%d %d", &Weight[c], &Price[c]);

    for(int i=0;i<=N;i++){
        for(int w=0;w<=G;w++){
            if(i==0 || w==0)
                dp[i][w]=0;
            else if(Weight[i]<=w)
                dp[i][w]= max(Price[i]+dp[i-1][w-Weight[i]],dp[i-1][w]); 
            else 
                dp[i][w]= dp[i-1][w];
        }
        for(int a=0;a<=i;a++){
            for(int b=0;b<=G;b++)
                printf("%d ", dp[a][b]);
            printf("\n");
        }
        printf("\n");
    }
    

    //minimize weight
    int stop=0;
    for(int i=1;i<=G;i++){
        if(dp[N][i]==dp[N][G]){
            stop=i;
            break;
        }
    }
    int i=N,j=stop, k=0;
    int saved[N+1];
    while(i>0 && j>0){
        if(dp[i][j]== dp[i-1][j]){    //object is not included
            i--;
        } else {        //object is included
            saved[k++]=i;
            j=j-Weight[i]; 
            i--;
        }
    }
    for(i=k-1;i>=0;i--)
        printf("%d\n", saved[i]);
    printf("optimal: %d\n", dp[N][G]);
    return 0;
}

