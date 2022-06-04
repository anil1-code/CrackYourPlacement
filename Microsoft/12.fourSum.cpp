vector<vector<int>> fourSum(vector<int> &arr, int sum) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    
    vector<int> freq(201);
    for(int i = 0; i < n; i++) freq[arr[i] + 100]++;
    
    bool present[201][201][201];
    memset(present, 0, sizeof present);
    vector<vector<int>> ans;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = j + 1; k < n - 1; k++) {
                int req = sum - arr[i] - arr[j] - arr[k];
                if(present[arr[i] + 100][arr[j] + 100][arr[k] + 100] or req < -100 or req > 100) continue;
                if((req > arr[k] and freq[req + 100]) or (req == arr[k] and arr[k] == arr[k + 1])) {
                    ans.push_back({arr[i], arr[j], arr[k], req});
                    present[arr[i] + 100][arr[j] + 100][arr[k] + 100] = 1;
                }
            }
        }
    }
    return ans;
}