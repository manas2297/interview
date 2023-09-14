class Solution {
public:
    int rob(vector<int>& nums) {
        
        vector<int> result(nums.size());

        result[0] = nums[0];
        int temp = 0;
        for(int i=1;i<nums.size();i++) {
            result[i] = max(result[i-1], temp + nums[i]);
            temp = result[i-1];
        }
        return result[nums.size()-1];
    }
};