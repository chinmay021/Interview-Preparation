void moveToFront(Node *head)  
{  

    if (head == NULL || head->next == NULL)  
        return;   
    Node *prev = NULL;  
    Node *last = *head;    
    while (last->next != NULL)  
    {  
        prev = last;  
        last = last->next;  
    }  
    prev->next = NULL; 
    last->next = head;    
    head = last;  
} 