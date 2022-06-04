void connect(Node *root) {
    queue<pair<Node*, int>> q;
    q.push({root, 1});
    Node* prev = NULL;
    int prev_level = 0;
    while(!q.empty()) {
        Node* nd = q.front().first;
        int lvl = q.front().second;
        q.pop();
        if(nd->left)
            q.push({nd->left, lvl + 1});
        if(nd->right)
            q.push({nd->right, lvl + 1});
        
        if(prev) {
            if(prev_level < lvl) {
                prev->nextRight = NULL;
            } else {
                prev->nextRight = nd;
            }
        }
        prev = nd;
        prev_level = lvl;
    }
    prev->nextRight = NULL;
}