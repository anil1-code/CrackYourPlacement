vector<int> leaders(int a[], int n){
    // Code here
    int mx = 0;
    vector<int> ans;
    for(int i = n - 1; i >= 0; i--) {
        if(a[i] >= mx) {
            mx = a[i];
            ans.push_back(a[i]);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}