class Solution {
    public:
    long long power(int N,int R) {
        int res = 1;
        while(R) {
            if(R % 2) res = 1LL * res * N % mod;
            N = 1LL * N * N % mod;
            R >>= 1;
        }
        return res;
    }
};