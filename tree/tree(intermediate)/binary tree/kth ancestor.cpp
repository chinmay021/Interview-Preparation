Node *kthAncestorDFS(Node *root, int node, int &k)
{
    if (!root)
        return NULL;

    if (root->data == node ||
        (temp = kthAncestorDFS(root->left, node, k)) ||
        (temp = kthAncestorDFS(root->right, node, k))) //only runs when we backtrack
    {
        if (k > 0)
            k--;

        else if (k == 0)
        {
            cout << "Kth ancestor is: " << root->data;

            // return NULL to stop further backtracking
            return NULL;
        }

        // return current node to previous call
        return root;
    }
}