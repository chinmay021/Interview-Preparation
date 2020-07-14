int countNodes(struct Node* head) 
{ 
    struct Node* temp = head; 
    int result = 0; 
    if (head == NULL)  return result;
    while(temp->next!=head){
    	result++;
    	temp=temp->next;
    } 
    return result+1; 
} 