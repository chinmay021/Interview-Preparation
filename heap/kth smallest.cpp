int kthSmallest(vector<int> &arr, int k)
{
    priority_queue<int> maxh;
    for (int i = 0; i < arr.size(); i++)
    {
        maxh.push(arr[i]);
        if (maxh.size() > k)
        {
            maxh.pop();
        }
    }
    return maxh.pop();
}