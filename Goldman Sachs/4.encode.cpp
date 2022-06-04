string encode(string src) {
    int len = src.length();
    string ans = "";
    for(int i = 0; i < len; i++) {
        int cnt = 1;
        while(i + 1 < len and src[i + 1] == src[i]) cnt++, i++;
        ans.push_back(src[i]);
        ans.append(to_string(cnt));
    }
    return ans;
}