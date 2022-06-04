string printMinNumberForPattern(string S) {
    string ans = "";
    int n = S.length();
    int mn = 1, mx = 9;
    vector<bool> used(10);
    for(int i = 0; i < n; i++) {
        int i_eff = i;
        while(i_eff + 1 < n and S[i_eff] == S[i_eff + 1]) {
            i_eff++;
        }
        if(S[i] == 'I') {
            int cnt = i_eff - i + 1;
            if(i == 0) cnt++;
            while(cnt--) {
                ans.push_back(char('0' + mn));
                used[mn] = 1;
                mn++;
                while(used[mn]) {
                    mn++;
                }
            }
        } else {
            if(i) {
                used[ans.back() - '0'] = 0;
                mn = ans.back() - '0';
                ans.pop_back();
            }
            i--;
            int cnt = i_eff - i + 1;
            string x = "";
            while(cnt--) {
                x.push_back(char('0' + mn));
                used[mn] = 1;
                mn++;
                while(used[mn]) {
                    mn++;
                }
            }
            reverse(x.begin(), x.end());
            ans.append(x);
        }
        i = i_eff;
    }
    return ans;
}