class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end()), mid;
        int ans = 0;
        while(l <= r) {
            mid = l + (r - l) / 2;
            int cnt = 0;
            for(int pile : piles) {
                cnt += (pile + mid - 1) / mid;
            }
            if(cnt <= h) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};