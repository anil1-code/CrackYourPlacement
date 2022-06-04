void matchPairs(char nuts[], char bolts[], int n) {
    vector<int> freq(9);
    char arr[9] = {'!', '#', '$', '%', '&', '*', '@', '^', '~'};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 9; j++) if(nuts[i] == arr[j]) freq[j]++;
    }
    int id = 0;
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < freq[i]; j++) nuts[id] = arr[i], bolts[id++] = arr[i];
    }
}