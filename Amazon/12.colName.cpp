string colName(long long int n) {
    string ans = "";
    while(n) {
        int r = n % 26;
        char c = 'A';
        if(r == 0) r = 26;
        c += (r - 1);
        ans.push_back(c);
        if(n == 26) break;
        n -= r;
        n /= 26;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}