int orangesRotting(vector<vector<int>>& grid) {
    queue<array<int, 3>> q;
    array<int, 3> temp, tmp;
    int h = grid.size(), w = grid[0].size();
    vector<vector<bool>> vis(h, vector<bool>(w));
    int cnt = h * w;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(grid[i][j] == 2) {
                temp = {i, j, 0};
                q.push(temp);
                vis[i][j] = 1;
            }
            if(grid[i][j] == 0) cnt--;
        }
    }
    int ans = 0;
    while(!q.empty()) {
        temp = q.front();
        q.pop();
        cnt--;
        ans = max(ans, temp[2]);
        if(temp[0] + 1 < h and grid[temp[0] + 1][temp[1]] == 1 and !vis[temp[0] + 1][temp[1]]) {
            tmp = {temp[0] + 1, temp[1], temp[2] + 1};
            q.push(tmp);
            vis[temp[0] + 1][temp[1]] = 1;
        }
        if(temp[0] - 1 >= 0 and grid[temp[0] - 1][temp[1]] == 1 and !vis[temp[0] - 1][temp[1]]) {
            tmp = {temp[0] - 1, temp[1], temp[2] + 1};
            q.push(tmp);
            vis[temp[0] - 1][temp[1]] = 1;
        }
        if(temp[1] + 1 < w and grid[temp[0]][temp[1] + 1] == 1 and !vis[temp[0]][temp[1] + 1]) {
            tmp = {temp[0], temp[1] + 1, temp[2] + 1};
            q.push(tmp);
            vis[temp[0]][temp[1] + 1] = 1;
        }
        if(temp[1] - 1 >= 0 and grid[temp[0]][temp[1] - 1] == 1 and !vis[temp[0]][temp[1] - 1]) {
            tmp = {temp[0], temp[1] - 1, temp[2] + 1};
            q.push(tmp);
            vis[temp[0]][temp[1] - 1] = 1;
        }
    }
    if(cnt) return -1;
    return ans;
}