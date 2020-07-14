void pairSum(struct Node *head, int x) 
{ 
 
    struct Node *first = head; 
    struct Node *second = head; 
    while (second->next != NULL) 
         second = second->next; 
    bool found = false; 
  
    // The loop terminates when either of two pointers 
    // become NULL, or they cross each other (second->next 
    // == first), or they become same (first == second) 
    while (first != NULL && second != NULL && 
           first != second && second->next != first) 
    { 
         if ((first->data + second->data) == x) 
         { 
              found = true; 
              cout << "(" << first->data<< ", "
                   << second->data << ")" << endl; 
              first = first->next;  
              second = second->prev; 
          } 
          else
          { 
              if ((first->data + second->data) < x) 
                 first = first->next; 
              else
                 second = second->prev; 
          } 
      }
      if (found == false) 
           cout << "No pair found"; 
} 