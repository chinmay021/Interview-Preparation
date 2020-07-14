Node* reverseDLL(Node * head)
{
    Node* current=head;
    Node* temp;
    Node* head_ref;
    while(current!=NULL){
        temp=current->prev;
        current->prev=current->next;
        current->next=temp;
        current=current->prev;
    }
    return temp->prev;//since temp points to last->prev(which is next element since it is reversed now) i.e NULL
}