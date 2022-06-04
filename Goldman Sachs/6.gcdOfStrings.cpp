string gcdOfStrings(string str1, string str2) {
    string ans = "";
    int mx_len = 0;
    for(int i = 0; i < (int)str1.length(); i++) {
        int i_eff = 0, j;
        for(j = 0; j < (int)str2.length(); j++) {
            if(str2[j] != str1[i_eff]) {
                break;
            }
            i_eff = (i_eff + 1);
            if(i_eff == i + 1) {
                i_eff = 0;
            }
        }
        if(j == (int)str2.length() and i_eff == 0) {
            for(j = i + 1; j < (int)str1.length(); j++) {
                if(str1[j] != str1[i_eff]) {
                    break;
                }
                i_eff++;
                if(i_eff == i + 1) i_eff = 0;
            }
            if(j == (int)str1.length() and i_eff == 0) {
                mx_len = max(mx_len, i + 1);
            }
        }
    }
    for(int i = 0; i < mx_len; i++) ans.push_back(str1[i]);
    return ans;
}