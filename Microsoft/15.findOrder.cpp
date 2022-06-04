void dfs(vector<vector<bool>>& adjM, char c, int k, vector<bool>& vis, string& order) {
    vis[c - 'a'] = 1;
    for(int i = 0; i < k; i++) {
        if(adjM[c - 'a'][i] and !vis[i]) {
            dfs(adjM, 'a' + i, k, vis, order);
        }
    }
    order.push_back(c);
}
// assuming the strings only contains the first k lowercase english letters
string findOrder(string dict[], int n, int k) {
    vector<vector<bool>> adjM(k, vector<bool>(k));
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int id = 0;
            while(true) {
                if(id == dict[i].length() or id == dict[j].length()) {
                    break;
                }
                if(dict[i][id] != dict[j][id]) {
                    adjM[dict[j][id] - 'a'][dict[i][id] - 'a'] = 1;
                    break;
                }
                id++;
            }
        }
    }
    vector<bool> vis(k);
    string ans = "";
    for(char c = 'a'; c < 'a' + k; c++) {
        if(!vis[c - 'a']) {
            string order;
            dfs(adjM, c, k, vis, order);
            ans.append(order);
        }
    }
    // can use kahn's algo also
    return ans;
}