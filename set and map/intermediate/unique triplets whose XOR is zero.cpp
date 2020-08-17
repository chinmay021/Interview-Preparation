int countTriplets(int a[], int n)
{
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
        s.insert(a[i]);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int xr = a[i] ^ a[j];
            if (s.find(xr) != s.end() && xr != a[i] &&
                xr != a[j])
                count++;
        }
    }
    return count / 3;
}