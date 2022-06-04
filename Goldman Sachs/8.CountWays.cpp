const int mod = 1'000'000'007;
int CountWays(string str) {
    int n = str.length();
    if(n == 0) {
        return 1;
    }
    vector<int> dp(n + 1);
    dp[n] = 1;
    for(int i = n - 1; i >= 0; i--) {
        if(str[i] == '0') {
            if(i > 0 and str[i - 1] > '0' and str[i - 1] < '3') {
                dp[i] = dp[i + 1];
                dp[i - 1] = dp[i];
                i--;
                continue;
            } else {
                return 0;
            }
        }
        if(i == n - 1) { 
            dp[i] = 1;
        } else {
            dp[i] = dp[i + 1];
            if(str[i] == '1' and (i + 2 >= n or str[i + 2] != '0')) {
                dp[i] = (dp[i] + dp[i + 2]) % mod;
            } else if(str[i] == '2' and str[i + 1] <= '6' and (i + 2 >= n or str[i + 2] != '0')) {
                dp[i] = (dp[i] + dp[i + 2]) % mod;
            }
        }
    }
    return dp[0];
}