class Solution {
public:
    vector<int> recoverArray(int n, vector<int>& sums) {
        // take the smallest element and find it's difference with
        sort(sums.begin(), sums.end());
        int f = sums.front();
        for(int& e : sums) e -= f;
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            int sz = sums.size();
            if(sz == 2) {
                ans.push_back(max(sums[0], sums[1]));
                break;
            }
            // sums[1] is an element
            int e = sums[1];
            ans.push_back(e);
            vector<int> temp;
            map<int, int> freq;
            for(int i = 0; i < sz; i++) {
                if(freq[sums[i]]) {
                    freq[sums[i]]--;
                    continue;
                }
                freq[sums[i] + e]++;
                temp.push_back(sums[i]);
            }
            swap(temp, sums);
        }
        for(int i = 0; i < (1 << n); i++) {
            int sum = 0;
            for(int bit = 0; bit < n; bit++) {
                if((1 << bit) & i) sum += ans[bit];
            }
            if(sum + f) continue;
            for(int bit = 0; bit < n; bit++) {
                if((1 << bit) & i) ans[bit] = -ans[bit];
            }
            break;
        }
        return ans;
    }
};