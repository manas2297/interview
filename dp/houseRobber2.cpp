class Solution {
public:
    int helper(vector<int> arr) {
        int n = arr.size();
        vector<int> dp(n);

        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]);

        for(int i=2;i<n;i++) {
            dp[i] = max(arr[i] + dp[i-2], dp[i-1]);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {

        if(nums.size() == 1) {
            return nums[0];
        } else if (nums.size()==2) {
            return max(nums[0], nums[1]);
        }
        vector<int> temp1, temp2;

        int n = nums.size();
        for(int i=0;i<n;i++) {
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        return max(helper(temp1), helper(temp2));
    }
};