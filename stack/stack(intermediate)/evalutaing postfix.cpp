#include <bits/stdc++.h>
using namespace std;
bool isOperator(char x)
{
    switch (x)
    {
    case '+':
    case '-':
    case '/':
    case '*':
        return true;
    }
    return false;
}
int postfixEval(string s)
{
    stack<int> st;
    for (int i = 0; i < s.size(); ++i)
    {
        if (isOperator(s[i]))
        {
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();
            char op = s[i];
            int temp;
            switch (op)
            {
            case '+':
                temp = op2 + op1;
                break;
            case '-':
                temp = op2 - op1;
                break;
            case '*':
                temp = op2 * op1;
                break;
            case '/':
                temp = op2 / op1;
                break;
            }
            st.push(temp);
        }
        else
        {
            st.push(s[i] - '0');
        }
    }
    return st.top();
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << postfixEval(s) << endl;
    }
    return 0;
}