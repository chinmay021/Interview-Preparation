TreeNode *helper(vector<int> &preorder, int &index, int upperBound)
{
    if (index == preorder.size() || preorder[index] > upperBound)
    {
        return NULL;
    }
    TreeNode *root = new TreeNode(preorder[index]);
    index++;
    root->left = helper(preorder, index, root->val);
    root->right = helper(preorder, index, upperBound);
    return root;
}
TreeNode *bstFromPreorder(vector<int> &preorder)
{
    int index = 0;
    return helper(preorder, index, INT_MAX);
}
}
;