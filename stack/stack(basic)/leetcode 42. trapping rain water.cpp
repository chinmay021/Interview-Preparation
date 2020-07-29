//O(N^2) O(1)
int maxWater(int arr[], int n)
{
    int res = 0;
    for (int i = 1; i < n - 1; i++)
    {
        int left = arr[i];
        for (int j = 0; j < i; j++)
        {
            left = max(left, arr[j]);
        }
        int right = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            right = max(right, arr[j]);
        }
        res = res + (min(left, right) - arr[i]);
    }
    return res;
}

//O(N) O(N)

int maxWater(int arr[], int n)
{
    int left[n], right[n];
    int water = 0;
    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i - 1], arr[i]);
    }
    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = max(right[i + 1], arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        water += min(left[i], right[i]) - arr[i];
    }
    return water;
}

//O(N) O(1)
//leetcode solution
int trap(vector<int> &height)
{
    if (height.size() == 0)
    {
        return 0;
    }
    int result = 0;
    int leftMax = INT_MIN;
    int rightMax = INT_MIN;
    for (int left = 0, right = height.size() - 1; left <= right;)
    {
        leftMax = max(leftMax, height[left]);
        rightMax = max(rightMax, height[right]);
        if (leftMax < rightMax)
        {
            result += leftMax - height[left];
            left++;
        }
        else
        {
            result += rightMax - height[right];
            right--;
        }
    }
    return result;
}