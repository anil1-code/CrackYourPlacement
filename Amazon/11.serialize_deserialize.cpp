vector<int> serialize(Node *root) {
    vector<int> ser;
    queue<Node*> q;
    q.push(root);
    ser.push_back(root->data);
    while(!q.empty()) {
        Node* f = q.front();
        q.pop();
        if(f) {
            q.push(f->left), q.push(f->right);
            if(f->left == NULL) ser.push_back(0);
            else ser.push_back((f->left)->data);
            if(f->right == NULL) ser.push_back(0);
            else ser.push_back((f->right)->data);
        }
    }
    // for(auto& e : ser) cout << e << ' ';
    // cout << endl;
    return ser;
}

//Function to deserialize a list and construct the tree.
Node* deSerialize(vector<int> &A) {
    Node* root = new Node(A[0]);
    // root->data = A[0];
    int ptr = 0;
    vector<Node*> temp = {root};
    for(int i = 1; i < (int)A.size(); i++) {
        if(A[i] == 0) temp[ptr]->left = NULL;
        else {
            Node* nd = new Node(A[i]);
            // nd->data = A[i];
            temp[ptr]->left = nd;
            temp.push_back(nd);
        }
        i++;
        if(i == (int)A.size() or A[i] == 0) temp[ptr]->right = NULL;
        else {
            Node* nd = new Node(A[i]);
            // nd->data = A[i];
            temp[ptr]->right = nd;
            temp.push_back(nd);
        }
        ptr++;
    }
    return root;
}