int toSumTreeUtil(Node *root, int &temp)
{
    if (root == NULL)
        return 0;
    int leftSum = toSumTreeUtil(root->left, temp);
    int rightSum = toSumTreeUtil(root->right, temp);
    temp = root->data;
    int sum = leftSum + rightSum;
    root->data = sum;
    return sum + temp;
}

void toSumTree(Node *root)
{
    int temp = 0;
    int temp2 = toSumTreeUtil(root, temp);
}
