vector<string> possibleWords(int a[], int N, int from = 0) {
    if(from == N) return {""};
    vector<string> v = possibleWords(a, N, from + 1);
    vector<string> ans;
    for(char c : arr[a[from]]) {
        for(string e : v) {
            string w = "";
            w.push_back(c);
            w.append(e);
            ans.push_back(w);
        }
    }
    return ans;
}