class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        auto cost = [&](int l, int r) {
            if(l > r) return 0;
            return dp[l][r];
        };
        // dp[i][j] is the minimum amount of money i need guess a number in range[i, j]
        for(int size = 2; size <= n; size++) {
            int start = 1, end = start + size - 1;
            while(end <= n) {
                int cst = (n + 3) * (n + 3);
                for(int guess = start; guess <= end; guess++) {
                    // if i guess guess then the amount i need
                    cst = min(cst, guess + max(cost(start, guess - 1), cost(guess + 1, end) ) );
                }
                dp[start][end] = cst;
                start++, end++;
            }
        }
        return dp[1][n];
    }
};