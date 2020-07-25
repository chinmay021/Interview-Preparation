
void inorder(TreeNode *node, vector<int> &res)
{
    if (node == nullptr)
        return;
    inorder(node->left, res);
    res.push_back(node->val);
    inorder(node->right, res);
}

vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
{
    if (!root1 && !root2)
        return {};
    vector<int> res1, res2, res;
    inorder(root1, res1);
    inorder(root2, res2);
    int i = 0, j = 0;
    while (i < res1.size() && j < res2.size())
    {
        if (res1[i] <= res2[j])
        {
            res.push_back(res1[i]);
            i++;
        }
        else
        {
            res.push_back(res2[j]);
            j++;
        }
    }
    while (i < res1.size())
    {
        res.push_back(res1[i]);
        i++;
    }
    while (j < res2.size())
    {
        res.push_back(res2[j]);
        j++;
    }
    return res;
}
