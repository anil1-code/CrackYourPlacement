class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int h = heights.size(), w = heights[0].size();
        vector<vector<int>> flow(h, vector<int>(w));
        queue<array<int, 2>> q;
        vector<vector<bool>> vis(h, vector<bool>(w));
        for(int i = 0; i < h; i++) {
            q.push({i, 0});
            vis[i][0] = 1;
        }
        for(int i = 1; i < w; i++) {
            q.push({0, i});
            vis[0][i] = 1;
        }
        auto fun = [&]() {
            while(!q.empty()) {
                auto cd = q.front();
                q.pop();
                flow[cd[0]][cd[1]]++;
                if(cd[0] - 1 >= 0 and heights[cd[0] - 1][cd[1]] >= heights[cd[0]][cd[1]] and !vis[cd[0] - 1][cd[1]]) q.push({cd[0] - 1, cd[1]}), vis[cd[0] - 1][cd[1]] = 1;
                if(cd[0] + 1 < h and heights[cd[0] + 1][cd[1]] >= heights[cd[0]][cd[1]] and !vis[cd[0] + 1][cd[1]]) q.push({cd[0] + 1, cd[1]}), vis[cd[0] + 1][cd[1]] = 1;
                if(cd[1] - 1 >= 0 and heights[cd[0]][cd[1] - 1] >= heights[cd[0]][cd[1]] and !vis[cd[0]][cd[1] - 1]) q.push({cd[0], cd[1] - 1}), vis[cd[0]][cd[1] - 1] = 1;
                if(cd[1] + 1 < w and heights[cd[0]][cd[1] + 1] >= heights[cd[0]][cd[1]] and !vis[cd[0]][cd[1] + 1]) q.push({cd[0], cd[1] + 1}), vis[cd[0]][cd[1] + 1] = 1;
            }
        };
        fun();
        for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) vis[i][j] = 0;
        for(int i = 0; i < h; i++) q.push({i, w - 1}), vis[i][w - 1] = 1;
        for(int i = 0; i < w - 1; i++) q.push({h - 1, i}), vis[h - 1][i] = 1;
        fun();
        vector<vector<int>> ans;
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(flow[i][j] == 2) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};