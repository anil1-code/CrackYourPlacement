class Solution {
    void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& vis, int n) {
        vis[node] = 1;
        for(int i = 0; i < n; i++) {
            if(isConnected[node][i] and !vis[i]) {
                dfs(i, isConnected, vis, n);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n);
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfs(i, isConnected, vis, n);
                cnt++;
            }
        }
        return cnt;
    }
};