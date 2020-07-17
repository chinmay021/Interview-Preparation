int isLeaf(Node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return 0;
}

int isSumTree(Node *root)
{
    int leftSum;
    int rightSum;

    /* If root is NULL or it's a leaf root then 
       return true */
    if (root == NULL || isLeaf(root))
        return 1;

    if (isSumTree(root->left) && isSumTree(root->right))
    {
        // Get the sum of roots in left subtree
        if (root->left == NULL)
            leftSum = 0;
        else if (isLeaf(root->left))
            leftSum = root->left->data;
        else
            leftSum = 2 * (root->left->data);

        // Get the sum of roots in right subtree
        if (root->right == NULL)
            rightSum = 0;
        else if (isLeaf(root->right))
            rightSum = root->right->data;
        else
            rightSum = 2 * (root->right->data);
        return (root->data == leftSum + rightSum);
    }

    return 0;
}