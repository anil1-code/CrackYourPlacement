/* matrix : given input matrix, you are require 
 to change it in place without using extra space */
void rotate(vector<vector<int> >& matrix) {
    int n = matrix.size();
    auto dbg = [&]() {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << matrix[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    };
    for(int i = 0; i < n - 1 - i; i++) {
        for(int j = i, k = i; k < n - 1 - i; k++) {
            int temp = matrix[j][k];
            matrix[j][k] = matrix[k][n - 1 - i];
            matrix[k][n - 1 - i] = matrix[n - 1 - i][n - 1 - k];
            matrix[n - 1 - i][n - 1 - k] = matrix[n - 1 - k][i];
            matrix[n - 1 - k][i] = temp;   
        }
        // dbg();
    }
}