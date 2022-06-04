vector<string> generate(int N) {
    vector<string> ans;
    for(int i = 1; i <= N; i++) {
        string s = "";
        int num = i;
        while(num) {
            char c = '0' + (num % 2);
            s.push_back(c);
            num >>= 1;
        }
        reverse(s.begin(), s.end());
        ans.push_back(s);
    }
    return ans;
}