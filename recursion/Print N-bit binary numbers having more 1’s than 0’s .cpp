#include <bits/stdc++.h>
using namespace std;

void solve(string op, int n, int zeros, int ones)
{
    if (n == 0)
    {
        cout << op << " ";
        return;
    }
    string op1 = op;
    op1.push_back('1');
    solve(op1, n - 1, zeros, ones + 1);
    if (ones > zeros)
    {
        string op2 = op;
        op2.push_back('0');
        solve(op2, n - 1, zeros + 1, ones);
        return;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string op = "";
        solve(op, n, 0, 0);
        cout << endl;
    }
}