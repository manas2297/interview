#include<bits/stdc++.h>

vector<vector<int> > stockBuySell(vector<int> A, int n){
        // code here
        vector<vector<int>>result;
        int start = 0;
        for(int i=1;i<n;i++){
            if(A[i-1] > A[i]) {
                if(start != i-1)
                result.push_back({start, i-1});
                start = i;                
            }

        }
        if(start!=n-1)
                result.push_back({start, n-1});   
        return result; 
    }