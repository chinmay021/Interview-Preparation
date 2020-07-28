#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long arr[n];
        for (long long i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<long long> v;
        stack<long long> s;
        for (long long i = n - 1; i >= 0; i--) // right to left
        {
            if (s.size() == 0)
            {
                v.push_back(-1);
            }
            else if (s.size() > 0 && s.top() > arr[i])
            {
                v.push_back(s.top());
            }
            else if (s.size() > 0 && s.top() <= arr[i])
            {
                while (s.size() > 0 && s.top() <= arr[i])
                {
                    s.pop();
                }
                if (s.size() == 0)
                {
                    v.push_back(-1);
                }
                else
                {
                    v.push_back(s.top());
                }
            }
            s.push(arr[i]);
        }
        for (auto i = v.rbegin(); i != v.rend(); ++i) // reversal
        {
            cout << *i << " ";
        }
        cout << "\n";
    }
    return 0;
}