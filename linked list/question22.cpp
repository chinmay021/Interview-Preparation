struct Node *exchangeNodes(struct Node *head) 
{ 
    // Find pointer to previous of last node 
    struct Node *p = head; 
    while (p->next->next != head) 
       p = p->next; 
      
    /* Exchange first and last nodes using 
       head and p */
    p->next->next = head->next; //last->next=2nd
    head->next = p->next;  //first->next=last
    p->next = head;         //last=head;
    head = head->next;      //shift head from last element to first element
  
    return head; 
} 
  


  // https://www.geeksforgeeks.org/exchange-first-last-node-circular-linked-list/