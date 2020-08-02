#include <bits/stdc++.h>
using namespace std;

void insertBottom(stack<int> &s, int ele)
{
    if (s.empty())
    {
        s.push(ele);
    }
    else
    {
        int temp = s.top();
        s.pop();
        insertBottom(s, ele);
        s.push(temp);
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
        int ele = s.top();
        s.pop();
        reverse(s);
        insertBottom(s, ele);
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