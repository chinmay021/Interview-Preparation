#define SIZE 99999
int A[SIZE];
int front = -1;
int rear = -1;

//function to check if queue is empty
bool isempty()
{
    if (front == -1 && rear == -1)
        return true;
    else
        return false;
}

//function to insert element in queue
void enqueue(int value)
{
    if (rear == SIZE - 1)
        cout << "Queue is full \n";
    else
    {
        if (front == -1)
            front = 0;
        rear++;
        A[rear] = value;
    }
}

//function to remove element from queue
void dequeue()
{
    if (isempty())
        cout << "Queue is empty\n";
    else if (front == rear)
        front = rear = -1;
    else
        front++;
}

//function to display element at front
void showfront()
{
    if (isempty())
        cout << "Queue is empty\n";
    else
        cout << "element at front is:" << A[front] << "\n";
}

//function to display elements of the queue
void displayQueue()
{
    if (isempty())
        cout << "Queue is empty\n";
    else
    {
        for (int i = front; i <= rear; i++)
            cout << A[i] << " ";
        cout << "\n";
    }
}