bool checkLeafLevelUtil(Node *root, int height, int &leafHeight)
{
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
    {
        if (leafHeight == 0)
        {
            leafHeight = height;
            return true;
        }
        if (height == leafHeight)
        {
            return true;
        }
        else
            return false;
    }
    return checkLeafLevelUtil(root->left, height + 1, leafHeight) && checkLeafLevelUtil(root->right, height + 1, leafHeight);
}

bool check(Node *root)
{
    int leafHeight = 0;
    int height = 0;
    return checkLeafLevelUtil(root, height, leafHeight);
}