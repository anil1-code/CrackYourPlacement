const unsigned long long inf = 1'000'000'000'000'00;
int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
    int prev = -1;
    unsigned long long prod = 1;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(prev == -1) {
            if(a[i] < k) 
                prev = i, cnt++, prod = a[i];
        } else {
            bool flag = ((prod > inf) and (a[i] > 10));
            if(!flag) prod *= a[i];
            while(prev <= i and (flag or prod >= k)) {
                prod /= a[prev];
                if(flag) {
                    bool x = ((prod > inf) and (a[i] > 10));
                    if(!x) {
                        flag = false;
                        prod *= a[i];
                    }
                }
                prev++;
            }
            cnt += (i - prev + 1);
            if(prev == i + 1) prev = -1, prod = 1;
        }
    }
    return cnt;
}