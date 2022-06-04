int* findTwoElement(int *arr, int n) {
    // code here
    long long sum_sq = 0, sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
        sum_sq += 1LL * arr[i] * arr[i];
    }
    long long temp = sum - 1LL * n * (n + 1) / 2;
    int* ans = new int[2];
    ans[0] = (temp + (sum_sq - 1LL * n * (n + 1) * (2 * n + 1) / 6) / temp) / 2;
    ans[1] = ((sum_sq - 1LL * n * (n + 1) * (2 * n + 1) / 6) / temp - temp) / 2;
    return ans;
}