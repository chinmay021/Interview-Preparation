int toSumTreeUtil(Node *root)
{
    if (root == NULL)
        return 0;
    int leftSum = toSumTreeUtil(root->left);
    int rightSum = toSumTreeUtil(root->right);
    int temp = root->data;
    int sum = leftSum + rightSum;
    root->data = leftSum + rightSum;
    return sum + temp;
}

void toSumTree(Node *root)
{
    int temp2 = toSumTreeUtil(root);
}