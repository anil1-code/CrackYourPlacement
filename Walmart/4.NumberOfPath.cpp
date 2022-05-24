class Solution
{
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b) {
        vector<vector<int>> dp(a, vector<int>(b));
        for(int i = 0; i < a; i++) {
            for(int j = 0; j < b; j++) {
                if(i == 0 and j == 0) {
                    dp[i][j] = 1;
                    continue;
                }
                dp[i][j] = ((i - 1 >= 0) ? dp[i - 1][j] : 0) + ((j - 1 >= 0) ? dp[i][j - 1] : 0);
            }
        }
        return dp[a - 1][b - 1];
    }
};
