// do a inorder traversal and store it into array and pass into function(minSwaps)
int minSwaps(int arr[], int n)
{
    pair<int, int> v[n];

    for (int i = 0; i < n; ++i)
    {
        v[i].first = arr[i];
        v[i].second = i;
    }
    sort(v, v + n);
    vector<bool> vis(n, false);
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (vis[i] || v[i].second == i)
        {
            continue;
        }
        int cycleSize = 0;
        int j = i;
        while (!vis[j])
        {
            vis[j] = true;
            j = v[j].second;
            cycleSize++;
        }
        if (cycleSize > 0)
        {
            ans += cycleSize - 1;
        }
    }
    return ans;
}