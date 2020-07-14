 Node* reverseList(Node *head)
{
    Node* current=head;
    Node* prev=NULL;
    Node* next;
    if(current==NULL)
        return NULL;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    return prev;
}