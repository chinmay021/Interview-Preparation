void replaceElements(int arr[], int n)
{
    int maxx = *max_element(arr, arr + n);

    unordered_set<int> s;

    for (int i = 0; i < n; i++)
    {

        if (s.find(arr[i]) == s.end())
            s.insert(arr[i]);
        else
        {
            arr[i] = maxx + 1;
            maxx = arr[i];
        }
    }
}