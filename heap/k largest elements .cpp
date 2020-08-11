int kLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> minh;
    for (int i = 0; i < arr.size(); i++)
    {
        minh.push(arr[i]);
        if (minh.size() > k)
        {
            minh.pop();
        }
    }
    while (minh.size() > 0)
    {
        cout << minh.top() << " ";
        minh.pop();
    }
}