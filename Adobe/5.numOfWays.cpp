const int mod = 1'000'000'007;
int numOfWays(int n, int x) {
    int power[n];
    for(int i = 0; i < n; i++) {
        int p = 1;
        for(int j = 0; j < x; j++) {
            p = 1LL * p * (i + 1) % mod;
        }
        power[i] = p;
    }
    vector<vector<int>> dp(n, vector<int>(n));
    // dp[i][j] is the number of ways to make the number i + 1 as the xth power of unique natural numbers such that the highest natural number among them is less than or equal to j + 1
    for(int i = 0; i < n; i++) dp[0][i] = 1;
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
            // use j + 1 as the highest number
            if(i + 1 - power[j] < 0)  dp[i][j] = dp[i][j - 1];
            else if(i + 1 - power[j] == 0) dp[i][j] = (dp[i][j - 1] + 1) % mod;
            else dp[i][j] = (dp[i - power[j]][j - 1] + dp[i][j - 1]) % mod;
        }
    }
    return dp[n - 1][n - 1];
}