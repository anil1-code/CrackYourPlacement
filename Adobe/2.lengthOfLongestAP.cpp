int lengthOfLongestAP(int A[], int n) {
    vector<int> ids(20005, -1);
    for(int i = 0; i < n; i++) ids[A[i]] = i;
    int ans = 1;
    vector<vector<int>> dp(n, vector<int>(n));
    // dp[i][j] is the length of the longest AP if the first two elements are i and j
    for(int i = n - 2; i >= 0; i--) {
        for(int j = i + 1; j < n; j++) {
            int id = ids[A[j] + A[j] - A[i]];
            if(id == -1) dp[i][j] = 2;
            else dp[i][j] = dp[j][id] + 1;
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}