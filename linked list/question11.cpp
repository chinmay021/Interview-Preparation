// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
};
Node* addOne(Node *head);
Node* newNode(int key)
{
    Node *temp = new Node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}
Node *ZZZZZZZZZZ(Node *head)
{
    Node * prev   = NULL;
    Node * current = head;
    Node * next;
    while (current != NULL)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
void print(struct Node *head)
{
	Node *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data;
		temp=temp->next;
	}
}
// This function mainly uses addOneUtil().
int main() {
	freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
	int T;
	cin>>T;
	int no;
	while(T--)
	{
		struct Node *head = NULL;
        struct Node *temp = head;
        
		cin>>no;
		while(no!=0)
			{
			if(head==NULL)
			head=temp=newNode(no%10);
			else
			{
				temp->next = newNode(no%10);
				temp=temp->next;
			}
			no/=10;
		}
		head = ZZZZZZZZZZ(head);
		
		head=addOne(head);
		print(head);
		cout<<endl;
	}
	return 0;
}// } Driver Code Ends


/* Node structure
struct Node
{
    int data;
    Node* next;
}; */


// Returns new head of linked List.
int addWithCarry(Node *head)
{
    if(head==NULL)
        return 1;
    int res=head->data+addWithCarry(head->next);
    
    head->data=res%10;
    return res/10;
}

Node *addOne(Node *head)
{
   int carry=addWithCarry(head);
   if(carry){
       Node *newNode= new Node;
       newNode->data=carry;
       newNode->next=head;
       head=newNode;
   }
   return(head);
}