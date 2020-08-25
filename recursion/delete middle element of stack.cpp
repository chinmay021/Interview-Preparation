stack<int> delMiddle(stack<int> s)
{
    if (s.size() == 0)
    {
        return s;
    }
    int k = s.size() / 2 + 1;
    solve(s, k);
    return s;
}

void solve(stack<int> &s, int k)
{
    if (k == 1)
    {
        s.pop();
        return;
    }
    int temp = s.top();
    s.pop();
    solve(s, k - 1);
    s.push(temp);
    return;
}