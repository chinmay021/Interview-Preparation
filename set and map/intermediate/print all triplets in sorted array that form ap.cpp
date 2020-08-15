#include <bits/stdc++.h>
using namespace std;

// Function to print all triplets in
// given sorted array that forms AP
void printAllAPTriplets(int arr[], int n)
{
    unordered_set<int> s;
    s.insert(arr[0]);
    // s.insert(arr[n - 1]);
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // Use hash to find if there is
            // a previous element with difference
            // equal to arr[j] - arr[i]
            int diff = arr[j] - arr[i];
            if (s.find(arr[i] - diff) != s.end())
                cout << arr[i] - diff << " " << arr[i]
                     << " " << arr[j] << endl;
        }
        s.insert(arr[i]);
    }
    // cout << "\n";
    // for (auto it = s.begin(); it != s.end(); ++it)
    // {
    //     cout << *it << " ";
    // }
}

// Driver code
int main()
{
    system("cls");
    int arr[] = {2, 6, 9, 12, 17, 22, 31, 32, 35, 42};
    int n = sizeof(arr) / sizeof(arr[0]);
    printAllAPTriplets(arr, n);
    return 0;
}