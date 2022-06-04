int minSteps(int D) {
    int l = 1, r = 150, mid;
    int val = r;
    while(l <= r) {
        mid = l + (r - l) / 2;
        int sum = mid * (mid + 1) / 2;
        if(sum >= D) {
            val = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    while((val * (val + 1) / 2 - D) % 2) {
        val++;
    }
    return val;
}