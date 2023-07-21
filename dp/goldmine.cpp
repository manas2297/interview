
#include<bits/stdc++.h>
int maxGold(int n, int m, vector<vector<int>> M)
    {
        for(int c = m-2; c>=0; c--){
            for(int r = 0; r<n;r++) {
                int R = M[r][c+1];
                int Ru = r ==0 ? 0:M[r-1][c+1];
                int Rd = r == (n-1) ? 0: M[r+1][c+1];
                
                M[r][c] = M[r][c] + max(max(R, Ru), Rd);
            }
        }
        int mG = 0;
        for(int i =0; i<n;i++) {
            mG = max(mG, M[i][0]);
        }
        return mG;
    }