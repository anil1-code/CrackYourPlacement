class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end()), r = (1 << 30), mid;
        int ans = r, sz = weights.size();
        while(l <= r) {
            mid = l + (r - l) / 2;
            // check whether this many days is sufficient 
            int cnt = 1, sum = 0;
            for(int i = 0; i < sz; i++) {
                sum += weights[i];
                if(sum > mid) {
                    sum = weights[i];
                    cnt++;
                }
            }
            if(cnt > days) {
                l = mid + 1;
            } else {
                ans = mid;
                r = mid - 1;
            }
        }
        return ans;
    }
};