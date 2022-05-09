class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN and divisor == -1) return INT_MAX;
        if(divisor == 1) return dividend;
        long long a = dividend, b = divisor;
        int cnt = 0;
        if(dividend < 0) cnt++, a = -a;
        if(divisor < 0) cnt++, b = -b;
        int ans = 0;
        for(int i = 30; i >= 0; i--) {
            if(a >= (b << i)) {
                ans += (1 << i);
                a -= (b << i);
            }
        }
        if(cnt == 1) ans = -ans;
        return ans;
    }
};