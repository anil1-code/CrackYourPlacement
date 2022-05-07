class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<int> pref(n, piles[0]);
        for(int i = 1; i < n; i++) pref[i] = pref[i - 1] + piles[i];
        auto range_sum = [&](int l, int r) {
            return pref[r] - (l ? pref[l - 1] : 0);
        };
        vector<vector<int>> dp(n, vector<int>(n));
        // dp[i][j] is the maximum score of the first player if they on the range [i, j] inclusive
        for(int size = 1; size <= n; size++) {
            int start = 0, end = start + size - 1;
            while(end < n) {
                if(size == 1) dp[start][end] = piles[start];
                else dp[start][end] = max(piles[start] + range_sum(start + 1, end) - dp[start + 1][end], piles[end] + range_sum(start, end - 1) - dp[start][end - 1]);
                start++,end++;
            }
        }
        return dp[0][n - 1] > range_sum(0, n - 1) - dp[0][n - 1];
    }
};