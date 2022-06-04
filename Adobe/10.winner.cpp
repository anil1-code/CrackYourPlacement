vector<string> winner(string arr[],int n) {
    map<string, int> mp;
    for(int i = 0; i < n; i++) {
        mp[arr[i]]++;
    }
    string s = ""; int vote = 0;
    for(auto e : mp) {
        if(e.second > vote) {
            vote = e.second;
            s = e.first;
        }
    }
    return {s, to_string(vote)};
}