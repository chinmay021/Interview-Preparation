bool isCircular(Node *head)
{
    Node*temp=head;
   while(head->next!=NULL && head->next!=temp){
       head=head->next;
   }
   if(head->next==NULL) return 0;
   else return 1;
}

