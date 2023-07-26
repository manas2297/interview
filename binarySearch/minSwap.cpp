int minSwaps(vector<int>& nums) {
    int n = nums.size();
    map<int, int> map;
    for (int i = 0; i < n; i++)
        map[nums[i]] = i;
 
    sort(nums.begin(), nums.end());
 
    // To keep track of visited elements. Initialize
    // all elements as not visited or false.
    bool visited[n] = { 0 };
 
    // Initialize result
    int ans = 0;
    for (int i = 0; i < n; i++) {
 
        // already swapped and corrected or
        // already present at correct pos
        if (visited[i] || map[nums[i]] == i)
            continue;
 
        int j = i, cycle_size = 0;
        while (!visited[j]) {
            visited[j] = true;
 
            // move to next node
            j = map[nums[j]];
            cycle_size++;
        }
 
        // Update answer by adding current cycle.
        if (cycle_size > 0) {
            ans += (cycle_size - 1);
        }
    }
    return ans;
}