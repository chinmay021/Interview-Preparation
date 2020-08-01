// using temporary stack

void sort(stack<int> &s)
{
    stack<int> temp;

    while (!s.empty())
    {
        int temp = s.top();
        s.pop();

        while (!temp.empty() && t.top() > temp)
        {
            int x = t.top();
            temp.pop();
            s.push(x);
        }
        temp.push(temp);
    }
    s = temp;
}

//using priority queue
void sort(stack<int> &s)
{
    priority_queue<int, vector<int>, greater<int>> q;
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }

    while (!q.empty())
    {
        s.push(q.top());
        q.pop();
    }
}