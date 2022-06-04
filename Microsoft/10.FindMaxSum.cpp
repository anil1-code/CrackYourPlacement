int FindMaxSum(int arr[], int n) {
    int a = arr[0], b = 0;
    int ans = a;
    for(int i = 1; i < n; i++) {
        if(i == 1) b = max(a, arr[1]);
        else {
            int temp = arr[i] + a;
            a = b;
            b = max(b, temp);
        }
        ans = max(ans, b);
    }
    return ans;
}