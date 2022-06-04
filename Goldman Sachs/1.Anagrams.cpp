vector<vector<string>> Anagrams(vector<string>& string_list) {
    unordered_map<string, int> s;
    vector<vector<string>> ans;
    for(int i = 0; i < (int)string_list.size(); i++) {
        string temp = string_list[i];
        sort(temp.begin(), temp.end());
        int id = s[temp];
        if(id == 0) {
            ans.push_back({string_list[i]});
            s[temp] = ans.size();
        } else {
            ans[id - 1].push_back(string_list[i]);
        }
    }
    return ans;
}