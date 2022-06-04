string ans(int l, int r, string& s, vector<int>& match) {
    string ret = "";
    for(int i = l; i <= r; i++) {
        if(s[i] == '[') {
            string res = ans(i + 1, match[i] - 1, s, match);
            string temp = res;
            string num = "";
            int x = i - 1;
            while(x >= l and s[x] >= '0' and s[x] <= '9') {
                num.push_back(s[x]);
                x--;
            }
            reverse(num.begin(), num.end());
            x = stoi(num);
            x--;
            while(x--) temp.append(res);
            ret.append(temp);
            i = match[i];
        } else if(s[i] >= 'a' and s[i] <= 'z') {
            ret.push_back(s[i]);
        }
    }
    return ret;
}
string decodedString(string s) {
    int n = s.length();
    vector<int> match(n);
    stack<int> ids;
    for(int i = 0; i < n; i++) {
        if(s[i] == '[') {
            ids.push(i);
        } else if(s[i] == ']') {
            match[ids.top()] = i;
            ids.pop();
        } 
    }
    return ans(0, n - 1, s, match);
}