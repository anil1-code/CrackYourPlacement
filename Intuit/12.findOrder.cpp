class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> vis(numCourses);
        vector<int> graph[numCourses];
        vector<int> indegree(numCourses);
        for(auto& e : prerequisites) {
            graph[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }
        vector<int> ans;
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(!indegree[i]) {
                q.push(i);
                ans.push_back(i);
                vis[i] = 1;
            }
        }
        while(!q.empty()) {
            auto f = q.front();
            q.pop();
            for(int nbr : graph[f]) {
                indegree[nbr]--;
                if(!indegree[nbr]) {
                    q.push(nbr);
                    ans.push_back(nbr);
                    vis[nbr] = 1;
                }
            }
        }
        reverse(begin(ans), end(ans));
        if((int)ans.size() != numCourses) ans.clear();
        return ans;
    }
};