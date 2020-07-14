int search(int val, int in[], int in_start, int in_end)
{
    for (int i = in_start; i <= in_end; ++i)
    {
        if (in[i] == val)
            return i;
    }
}
Node *buildTreeHelper(int &in[], int &pre[], int &pre_start, int in_start, int in_end)
{
    if (in_start > in_end)
    {
        return NULL;
    }
    int val = pre[pre_start];
    Node *node = new Node(val);
    int root = search(val, in, in_start, in_end);
    pre_start++;
    node->left = buildTree(in, pre, pre_start, in_start, root - 1);
    node->right = buildTree(in, pre, pre_start, root + 1, in_end);
    return node;
}

Node *buildTree(int in[], int pre[], int inStrt, int inEnd)
{
    return buildTreeHelper(in, pre, 0, inStrt, inEnd);
}