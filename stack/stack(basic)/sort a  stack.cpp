// using temporary stack

void sort(stack<int> &s)
{
    stack<int> t;

    while (!s.empty())
    {
        int temp = s.top();
        s.pop();

        while (!t.empty() && t.top() > temp)
        {
            int x = t.top();
            t.pop();
            s.push(x);
        }
        t.push(temp);
    }
    s = t;
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