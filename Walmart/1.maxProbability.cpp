class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int, double>> graph[n];
        int flag = 0;
        for(auto& e : edges) {
            graph[e[0]].push_back({e[1], succProb[flag]});
            graph[e[1]].push_back({e[0], succProb[flag]});
            flag++;
        }
        queue<int> q;
        q.push(end);
        vector<double> ans(n);
        ans[end] = 1;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto nbr : graph[node]) {
                if(ans[nbr.first] < ans[node] * nbr.second) {
                    ans[nbr.first] = ans[node] * nbr.second;
                    q.push(nbr.first);
                }
            }
        }
        return ans[start];
    }
};