// O(N) (1)
stack<int> s;
int minEle;

void push(int x)
{
    if (s.size() == 0)
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
    if (s.size() == 0)
        return;
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
    if (s.size() == 0)
        return NULL;
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

int getMin()
{
    if (s.size() == 0)
        return NULL;
    return minEle;
}