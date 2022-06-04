vector<string> AllParenthesis(int n) {
    if(n == 0) return {""};
    vector<string> ans;
    for(int i = 0; i < n; i++) {
        vector<string> ret1 = AllParenthesis(i);
        vector<string> ret2 = AllParenthesis(n - 1 - i);
        for(string& s : ret1) {
            string temp = "(";
            temp.append(s);
            temp.push_back(')');
            for(string& t : ret2) {
                string e = temp;
                e.append(t);
                ans.push_back(e);
            }
        }
    }
    return ans;
}