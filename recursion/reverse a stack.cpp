
void reverse(stack<int> &s)
{
    if (s.size() == 1)
    {
        return;
    }
    int temp = s.top();
    s.pop();
    reverse();
    pushBottom(s, temp);
    return;
}

void pushBottom(stack<int> &s, int ele)
{
    if (s.empty())
    {
        s.push(ele);
        return;
    }
    int temp = s.top();
    s.pop();
    pushBottom(s, ele);
    s.push(temp);
    return;
}