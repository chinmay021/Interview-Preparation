// O(N) (N)
stack<int> s;
int minEle;

void push(int x)
{
    s.push(x);
    if (ss.size() == 0 || x <= ss.top())
        ss.push(x);
}

int pop()
{
    if (s.size() == 0)
        return -1;
    int ans = s.top();
    s.pop();
    if (ss.top() == ans)
        ss.pop();
    return ans;
}

int top()
{
    if (s.size() == 0)
        return -1;
    return s.top();
}

int getMin()
{
    if (s.size() == 0)
        return -1;
    return ss.top();
}

//O(N) (N) but without another stack

int minEle;

int getMin()
{
    if (s.empty())
        return -1;
    return minEle;
}

void push(int x)
{
    if (s.empty())
    {
        s.push(x);
        minEle = x;
    }
    else
    {
        if (x >= minEle)
        {
            s.push(x);
        }
        else
        {
            s.push(2 * x - minEle);
            minEle = x;
        }
    }
}

void pop()
{
    if (s.empty())
        return -1;
    else
    {
        if (s.top() >= minEle)
        {
            s.pop();
        }
        else
        {
            minEle = 2 * minEle - s.top();
            s.pop();
        }
    }
}

int top()
{
    if (s.empty())
        return -1;
    else
    {
        if (s.top() >= minEle)
        {
            return s.top();
        }
        else
        {
            return minEle;
        }
    }
}
