string amendSentence (string s) {
    string ans = "";
    for(char c : s) {
        if(c >= 'A' and c <= 'Z') {
            if(ans.length())
                ans.push_back(' ');
            c = c - 'A' + 'a';
        }
        ans.push_back(c);
    }
    return ans;
}