string matrixChainOrder(int p[], int n) {
    if(n == 2)
        return "A";
    int dp[n - 1][n - 1][2];
    // {val, breaking_point}
    for(int gap = 0; gap < n - 1; gap++) {
        for(int i = 0, j = i + gap; j < n - 1; i++, j++) {
            int mn_val = 0, mn_id = i;
            for(int k = i; k < j; k++) {
                int cost = dp[i][k][0] + dp[k + 1][j][0] + p[i] * p[k + 1] * p[j + 1];
                if(mn_val == 0 or mn_val > cost) {
                    mn_val = cost;
                    mn_id = k;
                }
            }
            dp[i][j][0] = mn_val;
            dp[i][j][1] = mn_id;
        }
    }
    vector<array<int, 2>> braces(n);
    // {closing, opening}
    queue<array<int, 2>> q;
    q.push({0, n - 2});
    while(!q.empty()) {
        auto f = q.front();
        q.pop();
        if(f[0] == f[1]) continue;
        int bp = dp[f[0]][f[1]][1];
        int x = f[0], y = bp + 1;
        if(x + 1 < y) {
            braces[x][1]++, braces[y][0]++;
        }
        x = y, y = f[1] + 1;
        if(x + 1 < y) {
            braces[x][1]++, braces[y][0]++;
        }
        array<int, 2> arr = {f[0], bp};
        q.push(arr);
        arr = {bp + 1, f[1]};
        q.push(arr);
    }
    string ans = "(";
    char c = 'A';
    for(int i = 0; i < n - 1; i++) {
        while(braces[i][0]--) {
            ans.push_back(')');
        }
        while(braces[i][1]--) {
            ans.push_back('(');
        }
        ans.push_back(c);
        c++;
    }
    while(braces[n - 1][0]--) {
        ans.push_back(')');
    }
    while(braces[n - 1][1]--) {
        ans.push_back('(');
    }
    ans.push_back(')');
    return ans;
}