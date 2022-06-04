int isValid(vector<vector<int>> mat){
    for(int i = 0; i < 9; i++) {
        vector<int> freq(10);
        for(int j = 0; j < 9; j++) {
            if(mat[i][j]) {
                if(freq[mat[i][j]]) {
                    return 0;
                }
                freq[mat[i][j]]++;
            }
        }
        fill(freq.begin(), freq.end(), 0);
        for(int j = 0; j < 9; j++) {
            if(mat[j][i]) {
                if(freq[mat[j][i]]) {
                    return 0;
                }
                freq[mat[j][i]]++;
            }
        }
        fill(freq.begin(), freq.end(), 0);
        int x = (i / 3) * 3, y = (i % 3) * 3;
        for(int p = 0; p < 3; p++, x++) {
            int yy = y;
            for(int q = 0; q < 3; q++, yy++) {
                if(mat[x][yy]) {
                    if(freq[mat[x][yy]]) {
                        return 0;
                    }
                    freq[mat[x][yy]]++;
                }
            }
        }
    }
    return 1;
}