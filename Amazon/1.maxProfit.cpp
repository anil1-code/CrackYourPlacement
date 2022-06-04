int maxProfit(int k, int n, int A[]) {
    int ans = 0;
    int mn = -(1 << 20);
    vector<vector<int>> dp1(n, vector<int>(k));
    // dp1[i][j] is the maximum profit if we have done j transactions(j buy + j sell) in the first i days
    vector<vector<int>> dp2(n, vector<int>(k));
    // dp2[i][j] is the maximum profit if we are doing jth buy(j buy + j - 1 sell) on this day
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) {
            if(j == 0) {
                // for dp1 -> buy and sell just one time
                // for dp2 -> buy just one and sell nothing
                if(i == 0) {
                    dp2[i][j] = -A[i];
                    // not possible for dp1
                } else {
                    dp2[i][j] = max(dp2[i - 1][j], -A[i]);
                    dp1[i][j] = max(((i > 1) ? dp1[i - 1][j] : mn), dp2[i - 1][j] + A[i]);
                }
            } else {
                dp1[i][j] = mn;
                if(i >= 2 * (j + 1)) {
                    dp1[i][j] = max(dp1[i][j], dp1[i - 1][j]);
                }
                if((i + 1) / 2 >= j + 1) {
                    dp1[i][j] = max(dp1[i][j], dp2[i - 1][j] + A[i]);
                }

                dp2[i][j] = mn;
                if((i + 1) / 2 >= j + 1) {
                    dp2[i][j] = max(dp2[i][j], dp2[i - 1][j]);
                }
                if(i >= 2 * j) {
                    dp2[i][j] = max(dp2[i][j], dp1[i - 1][j - 1] - A[i]);
                }
            }
            ans = max(ans, dp1[i][j]);
        }
    }
    return ans;
}