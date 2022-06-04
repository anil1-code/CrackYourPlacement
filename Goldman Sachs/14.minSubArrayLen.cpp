int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int ans = n + 1;
    long long sum = nums[0];
    int prev = 0;
    if(nums[prev] >= target) return 1;
    for(int i = 1; i < n; i++) {
        sum += nums[i];
        while(sum - nums[prev] >= target) {
            sum -= nums[prev++];
        }
        if(sum >= target)
            ans = min(ans, i - prev + 1);
    }
    if(ans == n + 1) ans = 0;
    return ans;
}