int longestSubarray(int a[], int n, int x)
{
    int curr_max = 0;

    int maxLength = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > x)
        {
            curr_max += 1;
        }
        else
        {

            maxLength = max(maxLength, curr_max);

            curr_max = 0;
        }
    }
    if (curr_max)
        maxLength = max(maxLength, curr_max);

    return maxLength;
}