void dfs(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<bool>>& vis, int& cnt) {
    if(i == n or j == m or i == -1 or j == -1 or vis[i][j] or !grid[i][j]) return;
    cnt++;
    vis[i][j] = 1;
    dfs(i + 1, j, n, m, grid, vis, cnt);
    dfs(i, j + 1, n, m, grid, vis, cnt);
    dfs(i - 1, j, n, m, grid, vis, cnt);
    dfs(i, j - 1, n, m, grid, vis, cnt);
    dfs(i - 1, j - 1, n, m, grid, vis, cnt);
    dfs(i + 1, j - 1, n, m, grid, vis, cnt);
    dfs(i - 1, j + 1, n, m, grid, vis, cnt);
    dfs(i + 1, j + 1, n, m, grid, vis, cnt);
}
int findMaxArea(vector<vector<int>>& grid) {
    int ans = 0;
    int n = grid.size(), m = grid[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] and !vis[i][j]) {
                int cnt = 0;
                dfs(i, j, n, m, grid, vis, cnt);
                ans = max(ans, cnt);
            }
        }
    }
    return ans;
}