class Solution {
  public:
    int minDifference(int arr[], int n) {
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += arr[i];
        }
        vector<bool> dp(sum + 1); dp[0] = 1;
        for(int i = 0; i < n; i++) {
            for(int j = sum; j >= arr[i]; j--) {
                if(!dp[j] and dp[j - arr[i]]) dp[j] = 1;
            }
        }
        int diff = sum;
        for(int i = 1; i <= sum; i++) {
            if(dp[i])
                diff = min(diff, abs(i - (sum - i)));
        }
        return diff;
    } 
};