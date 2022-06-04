vector<vector<string>> displayContacts(int n, string cnct[], string s) {
    int len = s.length();
    vector<vector<string>> ans;
    sort(cnct, cnct + n);
    vector<string> contact = {cnct[0]};
    for(int i = 1; i < n; i++) {
        if(cnct[i] != cnct[i - 1]) {
            contact.push_back(cnct[i]);
        }
    }
    n = contact.size();
    for(int i = 0; i < len; i++) {
        vector<string> temp;
        if(ans.empty()) {
            for(int j = 0; j < n; j++) {
                if(contact[j][i] == s[i]) temp.push_back(contact[j]);
            }
            if(temp.empty()) {
                temp.push_back("0");
            }
        } else {
            if(ans.back().size() == 1 and ans.back()[0] == "0") {
                temp.push_back("0");
            } else {
                for(string& e : ans.back()) {
                    if(e[i] == s[i]) {
                        temp.push_back(e);
                    }
                }
                if(temp.empty()) {
                    temp.push_back("0");
                }
            }
        }
        ans.push_back(temp);
    }
    return ans;
}