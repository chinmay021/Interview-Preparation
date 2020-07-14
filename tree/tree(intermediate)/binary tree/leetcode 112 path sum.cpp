/*Given a binary tree and a sum, determine
 if the tree has a root-to-leaf path such  that 
 adding up all the values along the path equals the given sum.*/
class Solution
{
public:
    bool hasPathSum(TreeNode *root, int sum)
    {
        if (root == NULL)
            return false;
        else if (root->right == NULL && root->left == NULL && sum - root->val == 0)
            return true;
        else
        {
            return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
        }
    }
};