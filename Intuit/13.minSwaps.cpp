class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> v(n);
        for(int i = 0; i < n; i++) {
            int z = 0;
            for(int j = n - 1; j >= 0; j--) {
                if(grid[i][j]) break;
                z++;
            }
            v[i] = z;
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            bool found = false;
            for(int j = i; j < n; j++) {
                if(v[j] >= n - i - 1) {
                    for(int k = j - 1; k >= i; k--) {
                        swap(v[k + 1], v[k]);
                    }
                    ans += j - i;
                    found = true;
                    break;
                }
            }
            if(!found) {
                return -1;
            }
        }
        return ans;
    }
};