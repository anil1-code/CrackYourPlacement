int valid(int first, const string& str, int n) {
    string temp = to_string(first);
    int i = 0, cnt = 0;
    int missing = -1;
    while(i < n) {
        if((int)temp.size() > 6) {
            return false;
        }
        int i_temp = i;
        for(char c : temp) {
            if(c != str[i]) {
                cnt++;
                missing = first;
                i = i_temp;
                break;
            }
            i++;
        }
        if(cnt == 2) return false;
        first++;
        temp = to_string(first);
    }
    if(cnt == 0) return false;
    return missing;
}

int missingNumber(const string& str) {
    int n = str.length();
    // let the first have only i digits
    string s = str.substr(0, 6);
    for(int i = 6; i >= 1; i--) {
        int res = valid(stoi(s), str, n);
        if(res) {
            return res;
        }
        s.pop_back();
        if(s.empty()) break;
    }
    return -1;
}