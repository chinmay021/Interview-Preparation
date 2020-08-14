void replaceElements(int arr[], int n)
{
    unordered_set<int> s;

    for (int i = 0; i < n; i++)
    {
        if (s.find(arr[i]) == s.end())
            s.insert(arr[i]);

        else
        {

            for (int j = arr[i] + 1; j < INT_MAX; j++)
            {
                if (s.find(j) == s.end())
                {
                    arr[i] = j;
                    s.insert(j);
                    break;
                }
            }
        }
    }
}
