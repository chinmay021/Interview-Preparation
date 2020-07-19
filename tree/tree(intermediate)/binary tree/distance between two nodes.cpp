Node *find_LCA(Node *root, int a, int b)
{
    if (root == NULL)
        return NULL;

    if (root->data == a || root->data == b)
        return root;

    Node *left = find_LCA(root->left, a, b);
    Node *right = find_LCA(root->right, a, b);

    if (left != NULL && right != NULL)
        return root;
    return left ? left : right;
}

int distance(Node *root, int value, int level)
{
    if (root == NULL)
        return -1;

    if (root->data == value)
        return level;

    int left, right;
    left = distance(root->left, value, level + 1);
    right = distance(root->right, value, level + 1);

    return max(left, right);
}

int findDist(Node *root, int a, int b)
{
    Node *lca = find_LCA(root, a, b);
    int d1 = distance(lca, a, 0);
    int d2 = distance(lca, b, 0);
    return d1 + d2;
}