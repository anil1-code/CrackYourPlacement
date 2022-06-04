vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) {
    int dr = 0, dc = 1;
    int left = -1, right = c, up = -1, down = r;
    auto change = [&](int i, int j) {
        if(dc == 1) {
            // right, change to down
            dr = 1, dc = 0;
            up = i;
        } else if(dc == -1) {
            // left, change to up
            dr = -1, dc = 0;
            down = i;
        } else if(dr == 1) {
            // down, change to left
            dc = -1, dr = 0;
            right = j;
        } else {
            // up, change to right
            dc = 1, dr = 0;
            left = j;
        }
    };
    auto inside = [&](int r, int c) {
        return left < c and c < right and up < r and r < down;
    };
    int i = 0, j = 0;
    vector<int> ans;
    while(true) {
        ans.push_back(matrix[i][j]);
        if(inside(i + dr, j + dc)) {
            i += dr, j += dc;
        } else {
            change(i, j);
            if(inside(i + dr, j + dc)) {
                i += dr, j += dc;
            } else {
                break;
            }
        }
    }
    return ans;
}