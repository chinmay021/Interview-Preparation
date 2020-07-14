class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head;
        ListNode *fast=head;
        while(slow && fast && fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(slow == fast ){
                fast=head;
                //uses floyd's warshell algorithm
                while(fast!=slow){
                    fast=fast->next;
                    slow=slow->next;
                }
                return fast;
            }
        }
        return NULL;
    }
};