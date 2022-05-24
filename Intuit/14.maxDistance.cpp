class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int h = grid.size(), w = grid[0].size();
        vector<vector<int>> dist(h, vector<int>(w, h + w + 10));
        queue<pair<int, int>> q;
        int ans = 0;
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(grid[i][j]) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        while(!q.empty()) {
            auto nbr = q.front();
            q.pop();
            int x = nbr.first, y = nbr.second;
            if(x + 1 < h and dist[x + 1][y] > dist[x][y] + 1 and !grid[x + 1][y]) {
                dist[x + 1][y] = dist[x][y] + 1;
                q.push({x + 1, y});
                ans = max(ans, dist[x + 1][y]);
            }
            if(x - 1 >= 0 and dist[x - 1][y] > dist[x][y] + 1 and !grid[x - 1][y]) {
                dist[x - 1][y] = dist[x][y] + 1;
                q.push({x - 1, y});
                ans = max(ans, dist[x - 1][y]);
            }
            if(y + 1 < w and dist[x][y + 1] > dist[x][y] + 1 and !grid[x][y + 1]) {
                dist[x][y + 1] = dist[x][y] + 1;
                q.push({x, y + 1});
                ans = max(ans, dist[x][y + 1]);
            }
            if(y - 1 >= 0 and dist[x][y - 1] > dist[x][y] + 1 and !grid[x][y - 1]) {
                dist[x][y - 1] = dist[x][y] + 1;
                q.push({x, y - 1});
                ans = max(ans, dist[x][y - 1]);
            }
        }
        if(!ans) ans = -1;
        return ans;
    }
};