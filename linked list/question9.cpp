Node * removeDuplicates( Node *head) 
{
    map<int,bool> mymap;
    Node* current=head;
    Node* prev=NULL;
    Node* next=NULL;
    while(current!=NULL)
    {
        if(mymap[current->data]==false){
            mymap[current->data]=true;
            next=current->next;
            prev=current;
        }
        else if(mymap[current->data]==true){
            prev->next=current->next;
            delete(current);
        }
        current=prev->next;
    }
    return head;
}