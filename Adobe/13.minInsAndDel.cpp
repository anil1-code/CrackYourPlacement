int minInsAndDel(int A[], int B[], int n, int m) {
    int ssz = 0;
    if(m & (m - 1) == 0) ssz = m;
    else ssz = (1 << (32 - __builtin_clz(m)));
    vector<int> segment_tree(2 * ssz - 1);
    auto update = [&](int index, int value) {
        index += ssz - 1;
        segment_tree[index] = max(segment_tree[index], value);
        while(index) {
            index = (index - 1) / 2;
            segment_tree[index] = max(segment_tree[2 * index + 1], segment_tree[2 * index + 2]);
        }
    };
    auto range_query = [&](int node, int r_left, int r_right, int n_left, int n_right, auto&& range_query) {
        if(r_left <= n_left and n_right <= r_right) {
            return segment_tree[node];
        }
        if(n_right < r_left or r_right < n_left) {
            return 0;
        }
        int mid = (n_left + n_right) / 2;
        return max(
            range_query(2 * node + 1, r_left, r_right, n_left, mid, range_query),
            range_query(2 * node + 2, r_left, r_right, mid + 1, n_right, range_query)
        );
    };
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int id = lower_bound(B, B + m, A[i]) - B;
        if(id < m and B[id] == A[i]) {
            int val = range_query(0, 0, id - 1, 0, ssz - 1, range_query) + 1;
            ans = max(ans, val);
            update(id, val);
        }
    }
    return n - ans + m - ans;
}