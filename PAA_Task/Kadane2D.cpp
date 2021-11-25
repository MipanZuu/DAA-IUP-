/*
    Kadane2D.cpp
    2021-11-12 Denta Bramasta
*/

#include <bits/stdc++.h>
using namespace std;
int matrix[100][100] , temp[100] , top , bottom ;
int kadane(int N)
{
    int mx = INT_MIN , S=0 , localTop = 0 ;
    bool flag = false ;
    for(int i=0;i<N;i++)
    {
        if(temp[i]>=0) flag = true ;
        S=S+temp[i];
        if(S<0)
        {
            S=0;
            localTop = i+1 ;
        }
        else if(S>mx)
        {
            mx = S ;
            top = localTop ;
            bottom = i ;
        }
    }
    if(flag) return mx ;
    mx = INT_MIN;
    for(int i=0;i<N;i++)
    {
        if(mx<temp[i])
        {
            mx = temp[i] ;
            top = bottom = i ;
        }
    }
    return mx ;
}
void findMaxSum(int N)
{
    int maxSum = INT_MIN , finalTop , finalBottom , finalRight , finalLeft ;
    for(int left=0;left<N;left++)
    {
        fill(temp,temp+101,0);
        for(int right=left;right<N;right++)
        {
            for(int i=0;i<N;i++) 
            temp[i]+=matrix[i][right];
            int t = kadane(N);
            if(t>maxSum)
            {
                maxSum = t ;
                finalTop = top ;
                finalBottom = bottom ;
                finalLeft = left ;
                finalRight = right ;
            }
        }
    }
    // printf("(Top , Left) (%d, %d)\n", finalTop, finalLeft);
    // printf("(Bottom , Right) (%d, %d)\n", finalBottom, finalRight);
    cout << "The required sub matrix that will be sum is:"; 
    for (int i = finalTop; i <= finalBottom; i++)
    {
        cout << endl;
        for (int  j = finalLeft; j <= finalRight; j++)
        {
            cout << matrix[i][j] << " ";
        }
    }

    printf("\nMaximum sum is : %d\n", maxSum);
}
int main()
{
    int N ; // N is the number of rows and columns .
    while(scanf("%d",&N)==1)
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                scanf("%d",&matrix[i][j]);
            }
        }
        findMaxSum(N);
    }
    return 0;
}