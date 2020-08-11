vector<int> kSortedArray(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> minh;
    for (int i = 0; i < arr.size(); i++)
    {
        minh.push(arr[i]);
        if (minh.size() > k)
        {
            result.push_back(minh.top());
            minh.pop();
        }
    }
    while (minh.size() > 0)
    {
        result.push_back(minh.top());
        minh.pop();
    }
    return result;
}