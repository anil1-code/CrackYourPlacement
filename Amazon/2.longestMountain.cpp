int longestMountain(vector<int>& arr) {
    int ans = 0;
    int n = arr.size();
    int i = 1;
    while(i < n) {
        while(i < n and arr[i] <= arr[i - 1]) {
            i++;
        }
        if(i >= n - 1) break;
        int x = 1;
        while(i < n and arr[i] > arr[i - 1]) {
            x++;
            i++;
        }
        if(i == n or arr[i] == arr[i - 1]) continue;
        int y = 1;
        while(i + 1 < n and arr[i] > arr[i + 1]) {
            y++;
            i++;
        }
        ans = max(ans, x + y);
    }
    return ans;
}