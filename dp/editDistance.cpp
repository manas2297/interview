
// min steps required to convert s into t (by replacing , inserting or removing chars)

#include<bits/stdc++.h>
int editDistance(string s, string t) {
        // Code here
        int m = s.length();
        int n = t.length();
        
        vector<vector<int>>dp(m+1, vector<int>(n+1));
        
        for(auto i=0;i<=m;i++){
            for(auto j=0;j<=n;j++){
                if(i==0)
                dp[i][j] = j;
                else if(j==0)
                dp[i][j]=i;
                else if(s[i-1]==t[j-1])
                dp[i][j]=dp[i-1][j-1];
                else {
                    dp[i][j]=1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
                }
            }
        }
        return dp[m][n];
    }