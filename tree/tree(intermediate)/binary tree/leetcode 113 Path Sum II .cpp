/*Given a binary tree and a sum,
 find all root-to-leaf paths where
  each path's sum equals the given sum.*/

class Solution
{
public:
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        vector<vector<int>> paths;
        vector<int> current;
        findPaths(root, sum, current, paths);
        return paths;
    }

private:
    void findPaths(TreeNode *root, int sum, vector<int> &current, vector<vector<int>> &paths)
    {
        if (root == NULL)
            return;
        current.push_back(root->val);
        if (root->val == sum && root->left == NULL && root->right == NULL)
        {
            paths.push_back(current);
        }
        findPaths(root->left, sum - root->val, current, paths);
        findPaths(root->right, sum - root->val, current, paths);
        current.pop_back();
    }
};