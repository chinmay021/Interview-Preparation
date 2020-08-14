// Method 2 (Use Sorting)

// Sort the Array arr[] in ascending order. This step takes (O(nlogn)).
// Iterate through the array. Compare the value of index i to the number of elements after index i. If arr[i] equals the number of elements after arr[i], it is a noble Integer. Condition to check: (A[i] == length-i-1). This step takes O(n).
// Note: Array may have duplicate elements. So, we should skip the elements (adjacent elements in the sorted array) that are same.

// C++ program to find Noble elements
// in an array.
#include <bits/stdc++.h>
using namespace std;

// Returns a Noble integer if present,
// else returns -1.
int nobleInteger(int arr[], int n)
{
    sort(arr, arr + n);

    // Return a Noble element if present
    // before last.
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1])
            continue;

        // In case of duplicates, we
        // reach last occurrence here.
        if (arr[i] == n - i - 1)
            return arr[i];
    }
    if (arr[n - 1] == 0)
        return arr[n - 1];
    return -1;
}

// Driver code
int main()
{
    int arr[] = {10, 3, 20, 40, 2};
    int res = nobleInteger(arr, 5);
    if (res != -1)
        cout << "The noble integer is " << res;
    else
        cout << "No Noble Integer Found";
    return 0;
}

// Output :

// The noble integer is 3.
