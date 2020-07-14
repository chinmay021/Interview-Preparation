int countNodesinLoop(struct Node *head)
{
    Node *slow=head;
    Node *fast=head;
    while(slow && fast && fast->next)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(slow == fast ){
           // fast=head;
           int count=0;
            //m+k=length of loop(https://www.youtube.com/watch?v=LUm2ABqAs1w)
            //uses floyd's warshell algorithm
            while(fast->next!=slow){
                fast=fast->next;
                count++;
            }
            return count+1;
        }
    }
    return 0;
}