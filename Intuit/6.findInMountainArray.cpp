class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        // we can find the peak point in logn using binary search
        // we can then search the individual left and right part for the target value again using binary search
        int n = mountainArr.length();
        int l = 1, r = n - 1, mid;
        int peak = l;
        while(l <= r) {
            mid = l + (r - l) / 2;
            if(mountainArr.get(mid) > mountainArr.get(mid - 1)) {
                peak = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        l = 0, r = peak;
        while(l <= r) {
            mid = l + (r - l) / 2;
            if(mountainArr.get(mid) == target) {
                return mid;
            } else if(mountainArr.get(mid) > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        l = peak + 1, r = n - 1;
        while(l <= r) {
            mid = l + (r - l) / 2;
            if(mountainArr.get(mid) == target) {
                return mid;
            } else if(mountainArr.get(mid) > target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return -1;
    }
};