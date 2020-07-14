void deleteList(Node** head_ref)  
{  
      
/* deref head_ref to get the real head */
Node* current = *head_ref;  
Node* next;  
  
while (current != NULL)  
{  
    next = current->next;  
    free(current);  
    current = next;  
}  
      
/* deref head_ref to affect the real head back  
    in the caller. */
*head_ref = NULL;  
}  