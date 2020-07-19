int helper(Node *root, int &k, int node, int &ans)
{
    if (!root)
    {
        return 0;
    }
    if (root->data == node)
    {
        return 1;
    }
    if (helper(root->left, k, node, ans) || helper(root->right, k, node, ans))
    {
        k--;
        if (k == 0)
        {
            ans = root->data;
        }
        return 1;
    }
    return 0;
}
int kthAncestor(Node *root, int k, int node)
{
    if (!root || node == root->data)
        return -1;
    int ans = -1;
    helper(root, k, node, ans);
    return ans;
}
