class Solution
{
public:
    vector<TreeNode *> v;
    map<string, int> mp;
    string duplicate(TreeNode *root)
    {
        if (root == NULL)
        {
            return "#";
        }
        string x = duplicate(root->left);
        string y = duplicate(root->right);
        string temp = to_string(root->val) + ',' + x + ',' + y;
        mp[temp]++;
        if (mp[temp] == 2)
        {
            v.push_back(root);
        }
        return temp;
    }
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        duplicate(root);
        return v;
    }
};