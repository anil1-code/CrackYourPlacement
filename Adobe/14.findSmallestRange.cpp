pair<int,int> findSmallestRange(int arr[][N], int n, int k) {
    int ll = 1'00'000, rr = 0;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    for(int i = 0; i < k; i++) {
        pq.push({arr[i][0], {i, 0}});
        ll = min(ll, arr[i][0]);
        rr = max(rr, arr[i][0]);
    }
    int pl = ll, pr = rr;
    while(true) {
        auto itr = pq.top();
        int id1 = (itr.second.first);
        int id2 = (itr.second.second);
        if(id2 == n - 1) {
            break;
        }
        pq.pop();
        id2++;
        pl = max(pl, pq.top().first);
        pl = min(pl, arr[id1][id2]);
        pr = max(pr, arr[id1][id2]);
        pq.push({arr[id1][id2], {id1, id2}});
        if(rr - ll > pr - pl) {
            rr = pr;
            ll = pl;
        }
    }
    return {ll, rr};
}