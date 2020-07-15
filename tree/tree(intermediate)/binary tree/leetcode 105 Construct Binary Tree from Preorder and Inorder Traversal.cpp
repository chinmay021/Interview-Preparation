class Solution
{
public:
    TreeNode *buildTreeUtil(vector<int> &preorder, vector<int> &inorder, int &pre_index, int in_start, int in_end)
    {
        if (pre_index > preorder.size() || in_start > in_end)
        {
            return NULL;
        }
        TreeNode *node = new TreeNode(preorder[pre_index]);
        int index;
        for (int i = in_start; i <= in_end; ++i)
        {
            if (inorder[i] == preorder[pre_index])
            {
                index = i;
                break;
            }
        }
        pre_index++;
        node->left = buildTreeUtil(preorder, inorder, pre_index, in_start, index - 1);
        node->right = buildTreeUtil(preorder, inorder, pre_index, index + 1, in_end);
        return node;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.size() == 0)
            return NULL;
        int pre_start = 0;
        //buildTreeUtil(preorder, inorder, pre_start, inorder_start, inorder_end)
        return buildTreeUtil(preorder, inorder, pre_start, 0, inorder.size() - 1);
    }
};