queue<int> modifyQueue(queue<int> q, int k)
{
    if (q.empty())
    {
        return q;
    }
    stack<int> st;
    for (int i = 0; i < k; ++i)
    {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    int size = q.size();
    for (int i = 0; i < size - k; ++i)
    {
        q.push(q.front());
        q.pop();
    }
    return q;
}