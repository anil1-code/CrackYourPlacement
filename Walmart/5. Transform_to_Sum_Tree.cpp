class Solution {
  public:
    void toSumTree(Node *node) {
        int sum = 0;
        if(node->left != NULL) {
            sum += node->left->data;
            toSumTree(node->left);
            sum += node->left->data;
        }
        if(node->right != NULL) {
            sum += node->right->data;
            toSumTree(node->right);
            sum += node->right->data;
        }
        node->data = sum;
    }
};