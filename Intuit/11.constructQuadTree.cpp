class Solution {
    Node* rec(vector<vector<int>>& grid, int start_x, int start_y, int sz) {
        bool same = true;
        for(int i = 0; i < sz; i++) {
            for(int j = 0; j < sz; j++) {
                if(grid[start_x][start_y] != grid[i + start_x][j + start_y]) {
                    same = false;
                    break;
                }
            }
            if(!same) break;
        }
        if(same) {
            Node* node = new Node(grid[start_x][start_y], true);
            return node;
        } else {
            Node* topLeft = rec(grid, start_x, start_y, sz / 2);
            Node* topRight = rec(grid, start_x, start_y + sz / 2, sz / 2);
            Node* bottomLeft = rec(grid, start_x + sz / 2, start_y, sz / 2);
            Node* bottomRight = rec(grid, start_x + sz / 2, start_y + sz / 2, sz / 2);
            Node* node = new Node(1, false, topLeft, topRight, bottomLeft, bottomRight);
            return node;
        }
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        vector<Node> v;
        int n = grid.size();
        return rec(grid, 0, 0, n);
    }
};