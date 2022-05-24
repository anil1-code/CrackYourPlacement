class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size();
        int cntA = 0, cntB = 0;
        int A = 0, B = 0;
        for(int i = 0; i < n; i++) {
            if(colors[i] == 'A') {
                cntA++;
                B += max(cntB - 2, 0);
                cntB = 0;
            } else {
                cntB++;
                A += max(cntA - 2, 0);
                cntA = 0;
            }
        }
        A += max(cntA - 2, 0);
        B += max(cntB - 2, 0);
        return A > B;
    }
};