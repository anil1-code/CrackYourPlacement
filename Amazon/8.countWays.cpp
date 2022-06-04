long long countWays(int m) {
    vector<long long> dp(m + 1);
    dp[0] = 1;
    for(int step : {1, 2}) {
        for(int i = step; i <= m; i++) {
            dp[i] += dp[i - step];
        }
    }
    return dp[m];
}