#include <bits/stdc++.h>
using namespace std;
void subsequences(string ip, string op) //O(2^N)
{
    if (ip == "")
    {
        cout << op << "\n";
        return;
    }
    string op1 = op;
    string op2 = op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin() + 0);
    subsequences(ip, op1);
    subsequences(ip, op2);
    return;
}

int main()
{
    string ip;
    // cin>>ip;
    ip = "abc";
    string op = "";
    subsequences(ip, op);
    return 0;
}