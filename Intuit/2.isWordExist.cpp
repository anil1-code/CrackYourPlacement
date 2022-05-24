class Solution {
    bool ans = false;
    void dfs(vector<vector<char>>& board, int i, int j, int upto, string& word, vector<vector<bool>>& vis) {
        if(upto == (int)word.size() - 1) {
            ans = true;
            return;
        }
        vis[i][j] = 1;
        if(i - 1 >= 0 and board[i - 1][j] == word[upto + 1] and !vis[i - 1][j]) {
            dfs(board, i - 1, j, upto + 1, word, vis);
        }
        if(j - 1 >= 0 and board[i][j - 1] == word[upto + 1] and !vis[i][j - 1]) {
            dfs(board, i, j - 1, upto + 1, word, vis);
        }
        if(i + 1 < (int)board.size() and board[i + 1][j] == word[upto + 1] and !vis[i + 1][j]) {
            dfs(board, i + 1, j, upto + 1, word, vis);
        }
        if(j + 1 < (int)board[0].size() and board[i][j + 1] == word[upto + 1] and !vis[i][j + 1]) {
            dfs(board, i, j + 1, upto + 1, word, vis);
        }
        vis[i][j] = 0;
    }
public:
    bool isWordExist(vector<vector<char>>& board, string word) {
        int h = board.size(), w = board[0].size();
        int sz = word.size();
        vector<vector<bool>> vis(h, vector<bool>(w));
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(board[i][j] == word[0]) {
                    dfs(board, i, j, 0, word, vis);
                }
            }
        }
        return ans;
    }
};