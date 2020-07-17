class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if (!root)
            return;
        if (root->left)
        {
            TreeNode *last = root->left;
            while (last->right)
            {
                last = last->right;
            }
            TreeNode *temp = root->right;
            root->right = root->left;
            last->right = temp;
            root->left = NULL;
        }
        flatten(root->right);
    }
};