int findPosition(int N , int M , int K) {
    int r = (K + M - 1) % N;
    if(r == 0) r = N;
    return r;
}