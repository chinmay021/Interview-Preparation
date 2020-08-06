//using stack
queue<long long int> rev(queue<long long int> q)
{
    stack<int> Stack;
    while (!q.empty())
    {
        Stack.push(q.front());
        q.pop();
    }
    while (!Stack.empty())
    {
        q.push(Stack.top());
        Stack.pop();
    }
    return q;
}

//using recursion
void inplace_rev(queue<long long int> &q)
{
    if (q.empty())
        return;

    long long int front = q.front();
    q.pop();

    inplace_rev(q);

    q.push(front);
}

queue<long long int> rev(queue<long long int> q)
{
    // add code here.
    inplace_rev(q);
    return q;
}
