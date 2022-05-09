class Solution {
    const int inf = 1 << 30;
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, inf));
        dp[0][0] = 0;
        // dp[i][j] is the minimum largest sum if we partition the prefix i into j
        for(int i = 1; i <= m; i++) {
            for(int j = i - 1; j < n; j++) {
                // divide the prefix j into i parts
                int sum = 0;
                for(int k = j; k >= 0 and k >= i - 1; k--) {
                    sum += nums[k];
                    dp[j + 1][i] = min(dp[j + 1][i], max(sum, dp[k][i - 1]));
                }
                // cout << j << ' ' << i << ' ' << dp[j + 1][i] << endl;
            }
        }
        return dp[n][m];
    }
};