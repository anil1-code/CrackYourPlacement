class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int sz = points.size();
        int ans = 0;
        for(int i = 0; i < sz; i++) {
            // if the first point is this
            map<int, int> freq;
            for(int j = 0; j < sz; j++) {
                if(j == i) continue;
                int val = (points[j][0] - points[i][0]) * (points[j][0] - points[i][0]) + 
                    (points[j][1] - points[i][1]) * (points[j][1] - points[i][1]);
                freq[val]++;
            }
            for(auto& e : freq) {
                ans += e.second * (e.second - 1);
            }
        }
        return ans;
    }
};