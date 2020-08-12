vector<int> kClosest(vector<int> &nums, int k, int x)
{
    vector<int> ans;
    priority_queue<pair<int, int>> maxh;
    for (int i = 0; i < nums.size(); i++)
    {
        maxh.push({abs(nums[i] - x), nums[i]});
        if (maxh.size() > 0)
        {
            maxh.pop();
        }
    }
    while (maxh.size() > 0)
    {
        ans.push_back(maxh.top().second);
        maxh.pop();
    }
    return ans;
}