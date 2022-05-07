class Solution{
  public:
    vector<int> find3Numbers(vector<int> arr, int n) {
        vector<int> id(n, 1 << 20);
        int mn = arr[0];
        for(int i = 1; i < n - 1; i++) {
            if(arr[i] > mn) {
                id[i] = mn;
            } else {
                mn = arr[i];
            }
        }
        int mx = arr[n - 1];
        for(int i = n - 1; i >= 0; i--) {
            if(arr[i] < mx) {
                if(id[i] != (1 << 20)) {
                    return {id[i], arr[i], mx};
                }
            } else {
                mx = arr[i];
            }
        }
        return {};
    }
};