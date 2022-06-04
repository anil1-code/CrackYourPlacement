int countSubtreesWithSumX(Node* root, int X) {
    int ans = 0;
    auto dfs = [&](Node* node, auto&& dfs) {
        if(node == NULL) return 0;
        int sum = dfs(node->left, dfs) + dfs(node->right, dfs) + node->data;
        if(sum == X) ans++;
        return sum;
    };
    dfs(root, dfs);
    return ans;
}