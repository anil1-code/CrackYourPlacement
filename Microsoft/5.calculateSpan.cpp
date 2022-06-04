vector <int> calculateSpan(int price[], int n) {
    stack<pair<int, int>> st;
    vector<int> ans(n, 1);
    for(int i = 0; i < n; i++) {
        if(st.empty()) {
            st.push({price[i], 1});
        } else {
            while(!st.empty() and st.top().first <= price[i]) {
                ans[i] += st.top().second;
                st.pop();
            }
            st.push({price[i], ans[i]});
        }
    }
    return ans;
}