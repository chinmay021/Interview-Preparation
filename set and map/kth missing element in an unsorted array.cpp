#include <bits/stdc++.h>
using namespace std;
int findKth(int arr[], int n, int k)
{

    unordered_set<int> missing;
    int count = 0;

    for (int i = 0; i < n; i++)
        missing.insert(arr[i]);

    int maxm = *max_element(arr, arr + n);
    int minm = *min_element(arr, arr + n);

    for (int i = minm + 1; i < maxm; i++)
    {
        if (missing.find(i) == missing.end())
            count++;
        if (count == k)
            return i;
    }
    return -1;
}

// Driver code
int main()
{
    int arr[] = {2, 10, 9, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 5;
    cout << findKth(arr, n, k);

    return 0;
}
// Output:
// 8

// Input: arr[] = {2, 4, 10, 7}, k = 5
// Output: 9
// Missing elements in the given array: 3, 5, 6, 8, 9
// 5th missing is 9.