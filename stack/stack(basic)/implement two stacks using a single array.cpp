// dividing the array into two parts

int top1 = 0;
int top2 = n - 1;

void push1(int x)
{
    if (top1 == n / 2)
    {
        cout << "overflow";
        return;
    }
    else
    {
        arr[top1++] = x;
    }
}

void push2(int x)
{

    if (top1 == (n / 2 + 1))
    {
        cout << "overflow";
        return;
    }
    else
    {
        arr[top2--] = x;
    }
}

// Method to pop an element from first stack
int pop1()
{
    if (top1 < 0)
    {
        cout << "underflow";
        return;
    }
    else
    {
        cout << arr[top1--];
    }
}

// Method to pop an element
// from second stack
int pop2()
{
    if (top1 > n - 1)
    {
        cout << "underflow";
        return;
    }
    else
    {
        cout << arr[top2++];
    }
}

// space efficient stacks i.e one can use the space of the other
int top1 = 0;
int top2 = n - 1;

void push1(int x)
{
    if (top2 - top1 <= 1)
    {
        cout << "overflow";
        return;
    }
    else
    {
        arr[top1++] = x;
    }
}

void push2(int x)
{

    if (top2 - top1 <= 1)
    {
        cout << "overflow";
        return;
    }
    else
    {
        arr[top2--] = x;
    }
}

// Method to pop an element from first stack
int pop1()
{
    if (top1 < 0)
    {
        cout << "underflow";
        return;
    }
    else
    {
        cout << arr[top1--];
    }
}

// Method to pop an element
// from second stack
int pop2()
{
    if (top1 > n - 1)
    {
        cout << "underflow";
        return;
    }
    else
    {
        cout << arr[top2++];
    }
}