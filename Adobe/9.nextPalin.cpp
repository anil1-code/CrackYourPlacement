string nextPalin(string N) {
    int len = N.length();
    int l = (len - 2) / 2 - 1, r = len - 1 - l;
    map<char, int> mp;
    mp[N[l + 1]]++;
    while(l >= 0) {
        mp[N[l]]++;
        auto itr = mp.upper_bound(N[l]);
        if(itr != mp.end()) {
            N[l] = N[r] = (*itr).first;
            (*itr).second--;
            for(auto e : mp) {
                for(int f = 0; f < e.second; f++) {
                    N[++l] = N[--r] = e.first;
                }
            }
            return N;
        }
        l--, r++;
    }
    return "-1";
}