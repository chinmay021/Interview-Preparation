#include <bits/stdc++.h>
using namespace std;
void josephus(vector<int> &v, int k, int index, int &ans)
{
    if (v.size() == 1)
    {
        ans = v[0];
        return;
    }
    index = (index + k) % v.size();
    v.erase(v.begin() + index);
    josephus(v, k, index, ans);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int i, n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (i = 0; i < n; i++)
            v[i] = i + 1;
        k--;
        int ans = -1;
        int index = 0;
        josephus(v, k, index, ans);
        cout << ans << "\n";
    }
    return 0;
}