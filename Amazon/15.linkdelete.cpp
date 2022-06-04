void linkdelete(struct Node  *head, int m, int n) {
    Node* curr = head;
    while(curr) {
        for(int i = 0; i < m - 1; i++) {
            curr = curr->next;
            if(curr == NULL) return;
        }
        Node* first = curr;
        for(int i = 0; i < n + 1; i++) {
            if(curr == NULL) break;
            curr = curr->next;
        }
        first->next = curr;
    }
}