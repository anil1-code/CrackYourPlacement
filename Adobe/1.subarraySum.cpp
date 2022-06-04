vector<int> subarraySum(int arr[], int n, long long s) {
    int l = 0, r = 0;
    long long sum = arr[0];
    while(r < n) {
        if(sum > s) {
            sum -= arr[l++];
        } else if(sum < s) {
            r++;
            if(r == n) break;
            sum += arr[r];
        } else {
            return {l + 1, r + 1};
        }
    }
    return {-1};
}