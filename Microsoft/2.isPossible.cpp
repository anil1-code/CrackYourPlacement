bool isPossible(int n, vector<pair<int, int> >& prerequisites) {
    vector<int> graph[n];
    vector<int> indegree(n);
    for(auto& p : prerequisites) {
        graph[p.first].push_back(p.second);
        indegree[p.second]++;
    }
    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }
    int cnt = 0;
    while(!q.empty()) {
        auto e = q.front();
        cnt++;
        q.pop();
        for(int nbr : graph[e]) {
            indegree[nbr]--;
            if(indegree[nbr] == 0) q.push(nbr);
        }
    }
    return cnt == n;
}