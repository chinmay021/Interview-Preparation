struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *front = NULL;
Node *rear = NULL;

//Function to check if queue is empty or not
bool isempty()
{
    if (front == NULL && rear == NULL)
        return true;
    else
        return false;
}

//function to enter elements in queue
void enqueue(int value)
{
    Node *node = new Node(value);

    //If inserting the first element/node
    if (front == NULL)
    {
        front = node;
        rear = node;
    }
    else
    {
        rear->next = node;
        rear = node;
    }
}

//function to delete/remove element from queue
void dequeue()
{
    if (isempty())
        cout << "Queue is empty\n";

    //only one element/node in queue.
    else if (front == rear)
    {
        free(front);
        front = rear = NULL;
    }
    else
    {
        Node *temp = front;
        front = front->next;
        free(temp);
    }
}

//function to show the element at front
void showfront()
{
    if (isempty())
        cout << "Queue is empty\n";
    else
        cout << "element at front is:" << front->data;
}

//function to display queue
void displayQueue()
{
    if (isempty())
        cout << "Queue is empty\n";
    else
    {
        Node *temp = front;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
}