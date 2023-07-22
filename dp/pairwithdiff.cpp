int util(int arr[], int N, int K, int i, vector<int>&dp){
        if(i >= N){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        
        if(arr[i]-arr[i-1] < K) {
            return dp[i] = max(arr[i]+arr[i-1]+util(arr, N,K,i+2, dp), util(arr, N, K, i+1, dp));
        }
        return dp[i]=util(arr, N, K, i+1, dp);
        
    }
    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        // Your code goes here   
        sort(arr, arr+N);
        vector<int>dp(N, -1);
        return util(arr, N, K, 1, dp);
    }