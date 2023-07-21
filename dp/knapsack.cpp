/*
    You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
    Note that we have only one quantity of each item.
    In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. 
    Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. 
    You cannot break an item, either pick the complete item or dont pick it (0-1 property).
*/
#include<bits/stdc++.h>

int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(n+1, vector<int>(W+1,0));
       
       for(auto i = 0; i<n+1; i++) {
           for(auto j=0; j<W+1; j++) {
               if(j==0 || i == 0) {
                   dp[i][j]=0;
               }
               else if (wt[i-1] <= j) {
                   dp[i][j]= max(dp[i-1][j], val[i-1] + dp[i-1][j-wt[i-1]]);
               } else {
                   dp[i][j] = dp[i-1][j];
               }
           }
       }
       return dp[n][W];
    }

    int main(){
        return 0;
    }