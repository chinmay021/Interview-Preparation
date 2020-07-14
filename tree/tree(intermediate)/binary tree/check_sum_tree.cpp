int sum(Node *root)
{
    if (root == NULL)
        return 0;
    return root->data + sum(root->left) + sum(root->right);
}
bool isSumTree(Node *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return 1;
    }
    int leftSum = sum(root->left);
    int rightSum = sum(root->right);
    if (root->data == leftSum + rightSum && isSumTree(root->left) && isSumTree(root->right))
    {
        return 1;
    }
    return 0;
}