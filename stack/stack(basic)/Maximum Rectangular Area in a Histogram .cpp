#include <bits/stdc++.h>
using namespace std;
vector<int> nearestSmallestLeft(int arr[], int n)
{
    vector<int> v;
    stack<pair<int, int>> s;
    int psudo_index = -1;
    for (int i = 0; i < n; i++) // left to right
    {
        if (s.size() == 0)
        {
            v.push_back(psudo_index);
        }
        else if (s.size() > 0 && s.top().first < arr[i])
        {
            v.push_back(s.top().second);
        }
        else if (s.size() > 0 && s.top().first >= arr[i])
        {
            while (s.size() > 0 && s.top().first >= arr[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                v.push_back(psudo_index);
            }
            else
            {
                v.push_back(s.top().second);
            }
        }
        s.push({arr[i], i});
    }
    return v;
}

vector<int> nearestSmallestRight(int arr[], int n)
{
    vector<int> v;
    stack<pair<int, int>> s;
    int psudo_index = n;
    for (int i = n - 1; i >= 0; --i) // right to left
    {
        if (s.size() == 0)
        {
            v.push_back(psudo_index);
        }
        else if (s.size() > 0 && s.top().first < arr[i])
        {
            v.push_back(s.top().second);
        }
        else if (s.size() > 0 && s.top().first >= arr[i])
        {
            while (s.size() > 0 && s.top().first >= arr[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                v.push_back(psudo_index);
            }
            else
            {
                v.push_back(s.top().second);
            }
        }
        s.push({arr[i], i});
    }
    reverse(v.begin(), v.end());
    return v;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<int> left, right, width(n);
        left = nearestSmallestLeft(arr, n);
        right = nearestSmallestRight(arr, n);
        for (int i = 0; i < n; ++i)
        {
            width[i] = right[i] - left[i] - 1;
        }
        int maxArea = INT_MIN;
        for (int i = 0; i < n; ++i)
        {
            maxArea = max(maxArea, arr[i] * width[i]);
        }
        cout << maxArea << "\n";
    }

    return 0;
}