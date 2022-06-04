void dfs(vector<int> adj[], int node, vector<bool>& vis, bool flag, int c, int d) {
    vis[node] = 1;
    for(int nbr : adj[node]) {
        if(!vis[nbr]) {
            if((node == c and nbr == d) or (node == d and nbr == c)) {
                if(flag) {
                    dfs(adj, nbr, vis, flag, c, d);
                }
            } else {
                dfs(adj, nbr, vis, flag, c, d);
            }
        }
    }
}
int isBridge(int V, vector<int> adj[], int c, int d) {
    vector<bool> vis(V);
    bool flag = true;
    int c1 = 0, c2 = 0;
    for(int i = 0; i < V; i++) {
        if(!vis[i]) {
            c1++;
            dfs(adj, i, vis, flag, c, d);
        }
    }
    fill(vis.begin(), vis.end(), false);
    flag = false;
    for(int i = 0; i < V; i++) {
        if(!vis[i]) {
            c2++;
            dfs(adj, i, vis, flag, c, d);
        }
    }
    return c1 < c2;
}