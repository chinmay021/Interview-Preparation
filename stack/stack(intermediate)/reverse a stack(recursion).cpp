#include <bits/stdc++.h>
using namespace std;

void insertBottom(stack<int> &s, int temp)
{
    if (s.empty())
    {
        s.push(temp);
    }
    else
    {
        int temp2 = s.top();
        s.pop();
        insertBottom(s, temp);
        s.push(temp2);
    }
}
void reverse(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }
    else
    {
        int temp = s.top();
        s.pop();
        reverse(s);
        insertBottom(s, temp);
    }
}

int main()
{
    // freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    stack<int> original = st;
    cout << "original stack -> ";
    while (!original.empty())
    {
        cout << original.top() << " ";
        original.pop();
    }
    cout << "\nreversed stack -> ";
    reverse(st);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}