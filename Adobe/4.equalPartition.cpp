int equalPartition(int N, int arr[]) {
    int sum = 0;
    for(int i = 0; i < N; i++) sum += arr[i];
    if(sum % 2) return 0;
    sum /= 2;
    vector<bool> dp(sum + 1);
    dp[0] = 1;
    for(int i = 0; i < N; i++) {
        for(int j = sum; j >= arr[i]; j--) {
            if(!dp[j] and dp[j - arr[i]]) dp[j] = 1;
        }
    }
    return dp[sum];
}