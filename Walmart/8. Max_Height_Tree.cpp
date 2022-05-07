class Solution{
public:
    int height(int N){
        int l = 0, r = 500, mid;
        int ans = 0;
        while(l <= r) {
            mid = l + (r - l) / 2;
            if(mid * (mid + 1) / 2 <= N) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};