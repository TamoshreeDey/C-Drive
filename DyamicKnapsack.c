#include <stdio.h>
#include <stdlib.h>
int max(int a, int b){
    return a>b?a:b;
}
int knapsack(int val[], int wt[], int n, int W){
    int dp[n+1][W+1];

    for(int i=0;i<=n;i++){
        for(int w=0;w<=W;w++){
            if(i==0 || w==0){
                dp[i][w]=0;
            }else if(wt[i-1]<=w){
                dp[i][w]=max(val[i-1]+dp[i-1][w-wt[i-1]],dp[i-1][w]);
            }else{
                dp[i][w]=dp[i-1][w];
            }
        }
    }
    return dp[n][W];
}
int main()
{
    int wt[] = {3, 2, 4, 5, 1};
    int val[]  = {50, 40, 70, 80, 10};
    int n = sizeof(wt) / sizeof(wt[0]);
    int W = 7;
    int value=knapsack(val,wt,n,W);
    printf("%d ",value);
    return 0;
}
