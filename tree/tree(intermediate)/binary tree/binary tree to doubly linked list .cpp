void bToDLL(Node *root, Node **head)
{
    static Node *prev = NULL;
    if (!root)
        return;
    // left
    bToDLL(root->left, head);
    // process
    if (*head == NULL)
        *head = root;

    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    //right
    bToDLL(root->right, head);
}