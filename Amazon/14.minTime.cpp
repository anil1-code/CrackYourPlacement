// {target_on_the_Subtree, if_not_then_max_height}
pair<bool, int> dfs(Node* root, int& ans, int target) {
    if(root == NULL) return {0, 0};
    pair<bool, int> p1 = dfs(root->left, ans, target);
    pair<bool, int> p2 = dfs(root->right, ans, target);
    if(root->data == target) {
        ans = max({ans, p1.second, p2.second});
        return {1, 0};
    } else if(p1.first) {
        ans = max(ans, p1.second + p2.second + 1);
        return {1, p1.second + 1};
    } else if(p2.first) {
        ans = max(ans, p2.second + p1.second + 1);
        return {1, p2.second + 1};
    } else {
        return {0, max(p1.second, p2.second) + 1};
    }
}
int minTime(Node* root, int target) {
    int ans = 0;
    dfs(root, ans, target);
    return ans;
}