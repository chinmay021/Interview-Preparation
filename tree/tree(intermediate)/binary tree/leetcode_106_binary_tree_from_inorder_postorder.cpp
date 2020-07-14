 
    //here we build right subtree before left subtree
    // because we are using post order traversal
    // and we start traversing the postorder traversal
    // from the last since the root is a the last of a post order traversal
 int search(int val, vector<int>&target, int start, int end)
    {
        for (int i=start; i<=end; ++i){
            if(target[i]==val)
                return i;
        }
        return -1;
    }

    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int &post_last, int in_start, int in_end)
    {
        if(in_start > in_end)
        {
            return NULL;
        }

        int val = postorder[post_last];
        TreeNode* node = new TreeNode(val);

        int root_index = search(val, inorder, in_start, in_end);
        post_last--;
        node->right = buildTreeHelper(inorder, postorder, post_last, root_index + 1, in_end);
        node->left = buildTreeHelper(inorder, postorder, post_last, in_start, root_index - 1);


        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        int root = postorder.size() - 1;
        return buildTreeHelper(inorder, postorder, root, 0, inorder.size() - 1);
    }