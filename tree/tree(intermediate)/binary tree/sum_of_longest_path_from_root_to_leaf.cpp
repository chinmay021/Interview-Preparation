void helper(Node *root, int curr_len, int curr_sum, int &max_sum, int &max_len)
{
    if (!root)
        return;
    if (!root->left && !root->right)
    {
        if (curr_len > max_len)
        {
            max_sum = curr_sum + root->data;
            max_len = curr_len;
        }
        else if (curr_len == max_len && curr_sum + root->data > max_sum)
        {
            max_sum = curr_sum + root->data;
        }
        return;
    }
    helper(root->left, curr_len + 1, curr_sum + root->data, max_sum, max_len);
    helper(root->right, curr_len + 1, curr_sum + root->data, max_sum, max_len);
}
int sumOfLongRootToLeafPath(Node *root)
{
    if (root == NULL)
        return 0;
    int curr_len = 0, curr_sum = 0;
    int max_len = 0;
    int max_sum = INT_MIN;
    helper(root, curr_len, curr_sum, max_sum, max_len);
    return max_sum;
}