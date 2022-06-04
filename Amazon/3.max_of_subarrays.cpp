vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
    deque<pair<int, int>> dq;
    dq.push_back({arr[0], 0});
    for(int i = 1; i < k; i++) {
        while(!dq.empty() and dq.back().first <= arr[i]) {
            dq.pop_back();
        }
        dq.push_back({arr[i], i});
    }
    vector<int> ans;
    ans.push_back(dq.front().first);
    for(int i = k; i < n; i++) {
        if(dq.front().second == i - k) dq.pop_front();
        while(!dq.empty() and dq.back().first <= arr[i]) {
            dq.pop_back();
        }
        dq.push_back({arr[i], i});
        
        ans.push_back(dq.front().first);
    }
    return ans;
}