bool checkLeafLevelUtil(Node *root, int level, int &leafHeight)
{
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
    {
        if (leafHeight == 0)
        {
            leafHeight = level;
            return true;
        }
        if (level == leafHeight)
        {
            return true;
        }
        else
            return false;
    }
    return checkLeafLevelUtil(root->left, level + 1, leafHeight) && checkLeafLevelUtil(root->right, level + 1, leafHeight);
}

bool check(Node *root)
{
    int leafHeight = 0;
    int level = 0;
    return checkLeafLevelUtil(root, level, leafHeight);
}