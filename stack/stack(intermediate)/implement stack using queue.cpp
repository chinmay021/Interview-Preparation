queue<int> q1; // supporting stack
queue<int> q2;

void push(int x)
{
    q1.push(x);
    while (!q2.empty())
    {
        q1.push(q2.front());
        q2.pop();
    }
    swap(q2, q1);
}

/*The method pop which return the element poped out of the stack*/
int pop()
{
    if (!q2.empty())
    {
        int x = q2.front();
        q2.pop();
        return x;
    }
    return -1;
}