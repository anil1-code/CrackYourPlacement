class Solution {
    private:
    void findMax(int i, int k, int n, string &str, string &ans) {
        for(int w = 0; w < n; w++) {
            if(str[w] > ans[w]) {
                ans = str;
                break;
            } else if(str[w] < ans[w]) break;
        }
        if(k<=0) {
            return;
        }
        vector<int> ids;
        char maxM = '0';
        for(int j = i + 1; j < n; j++) {
            if(str[j] > maxM) {
                maxM = str[j];
                ids = {j};
            } else if(str[j] == maxM) {
                ids.push_back(j);
            }
        }
        if(str[i] < maxM) {
            for(int id : ids) {
                swap(str[i], str[id]);
                findMax(i + 1, k - 1, n, str, ans);
                swap(str[i], str[id]);
            }
        } else {
            findMax(i + 1, k, n, str, ans);
        }
    }
    public:
    string findMaximumNum(string str, int k) {
        string ans = str;
        findMax(0, k, (int)str.length(), str, ans);
        return ans;
    }
};