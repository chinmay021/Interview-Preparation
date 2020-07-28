int maxArea(vector<vector<int>> &arr, int n, int m)
{
    vector<int> v;
    for (int j = 0; j < m; j++)
    {
        v.push_back(arr[0][j]);
    }
    int maxArea = maxAreaHistogram(v);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
                v[j] = 0;
            else
            {
                v[j] = v[j] + arr[i][j];
            }
        }
        maxArea = max(maxArea, maxAreaHistogram(v));
    }
    return maxArea;
}

vector<int> nearestSmallestLeft(vector<int> &arr)
{
    int n = arr.size();
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

vector<int> nearestSmallestRight(vector<int> &arr)
{
    int n = arr.size();
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
int maxAreaHistogram(vector<int> &arr)
{
    int n = arr.size();
    vector<int> left, right, width(n);
    left = nearestSmallestLeft(arr);
    right = nearestSmallestRight(arr);
    for (int i = 0; i < n; ++i)
    {
        width[i] = right[i] - left[i] - 1;
    }
    int maxArea = INT_MIN;
    for (int i = 0; i < n; ++i)
    {
        maxArea = max(maxArea, arr[i] * width[i]);
    }
    return maxArea;
}
