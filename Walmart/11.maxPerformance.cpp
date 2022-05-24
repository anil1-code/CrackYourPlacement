class Solution {
    const int mod = 1'000'000'007;
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<array<int, 2>> both(n);
        for(int i = 0; i < n; i++) both[i] = {speed[i], efficiency[i]};
        sort(both.begin(), both.end(), [](array<int, 2>& a1, array<int, 2>& a2) {
            return a1[1] < a2[1];
        });
        // if the minimum efficiency is at the ith index
        multiset<int> mst;
        long long sum = 0;
        long long ans = 0;
        for(int i = n - 1; i >= n - k + 1; i--) {
            mst.insert(both[i][0]);
            sum += both[i][0];
            ans = max(ans, sum * both[i][1]);
        }
        for(int i = n - k; i >= 0; i--) {
            ans = max(ans, (sum + both[i][0]) * both[i][1]);
            if(!mst.empty()) {
                auto itr = mst.begin();
                if(both[i][0] > *itr) {
                    sum = sum - *itr + both[i][0];
                    mst.erase(itr);
                    mst.insert(both[i][0]);
                }
            }
        }
        return ans % mod;
    }
};