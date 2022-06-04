vector<int> max_of_subarrays(int *arr, int n, int k) {
    deque<int> dq;
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        while(!dq.empty() and arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        if(i >= k - 1) {
            if(dq.front() == i - k) {
                dq.pop_front();
            }
            ans.push_back(arr[dq.front()]);
        }
    }
    return ans;
}