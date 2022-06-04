bool canPair(vector<int> nums, int k) {
    int n = nums.size();
    vector<int> dp(k);
    for(int i = 0; i < n; i++) {
        dp[nums[i] % k]++;
    }
    if(dp[0] % 2) return false;
    for(int l = 1, r = k - 1; l < r; l++, r--) {
        if(dp[l] != dp[r]) return false;
    }
    return true;
}