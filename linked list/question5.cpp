int detectloop(Node *head) {

    // your code here
    Node* fast = head;
    Node* slow = head;
    
    while( slow && fast && fast->next )
    {
    fast = fast->next->next;
    slow = slow->next;
    if(slow == fast)
        return 1;
    }
    
    return 0;
}