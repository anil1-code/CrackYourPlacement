int maxCoins(vector<int>&A,int n) {
    for(int i = 1; i < n; i++) A[i] += A[i - 1];
    auto range_sum = [&](int l, int r) {
        return A[r] - ((l > 0) ? A[l - 1] : 0);
    };
    vector<int> dp(n);
    for(int gap = 0; gap < n; gap++) {
        vector<int> temp(n);
        for(int i = 0, j = i + gap; j < n; j++,i++) {
            if(i == j) temp[i] = range_sum(i, j);
            else temp[i] = max(range_sum(i, i) + range_sum(i + 1, j) - dp[i + 1], range_sum(j, j) + range_sum(i, j - 1) - dp[i]);
        }
        swap(dp, temp);
    }
    return dp[0];
}