const int mod = 1'000'000'007;
int kvowelwords(int N, int K) {
    vector<vector<int>> dp(N, vector<int>(2));
    // dp[i] is the number of ways to make the prefix i of the required string
    dp[0][0] = 21;
    if(K)
        dp[0][1] = 5;
    for(int i = 1; i < N; i++) {
        dp[i][0] = 21LL * (dp[i - 1][0] + dp[i - 1][1]) % mod;
        int mul = 5;
        for(int j = 1; j <= K and i - j >= -1; j++) {
            if(i - j == -1) dp[i][1] = (dp[i][1] + mul) % mod;
            else dp[i][1] = (1LL * dp[i - j][0] * mul + dp[i][1]) % mod;
            mul = 5LL * mul % mod;
        }
    }
    return (dp[N - 1][0] + dp[N - 1][1]) % mod;
}