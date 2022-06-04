string FirstNonRepeating(string A){
    string ans = "";
    vector<int> freq(26);
    string temp = "";
    for(char c : A) {
        freq[c - 'a']++;
        if(freq[c - 'a'] == 1) {
            temp.push_back(c);
        }
        char f = '#';
        for(char ch : temp) {
            if(freq[ch - 'a'] == 1) {
                f = ch;
                break;
            }
        }
        ans.push_back(f);
    }
    return ans;
}