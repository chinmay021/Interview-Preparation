Node* reversed(Node* head ){
    Node* prev=NULL;
    Node* next;
    while(head!=NULL)
    {
        next=head->next;
        head->next=prev;
        prev=head;
        head=next;
    }
    return prev;
}
bool isPalindrome(Node *head)
{
    if(head==NULL||head->next==NULL)
        return true;
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    if(fast) slow=slow->next;
    slow=reversed(slow);
    fast=head;
    while(slow!=NULL)
    {
        if(slow->data!=fast->data)
            return false;
        slow=slow->next;
        fast=fast->next;
    }
    return true;
}

