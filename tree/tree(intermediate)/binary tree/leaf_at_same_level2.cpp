bool check(Node *root)
{
    queue<Node *> q;
    int s;
    bool flag = false;
    Node *temp;
    q.push(root);
    while (!q.empty())
    {
        s = q.size();
        while (s--)
        {
            temp = q.front();
            q.pop();
            if (temp->left == NULL && temp->right == NULL)
            {
                flag = true;
            }
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
        if (!q.empty() && flag)
            return false;
    }
    return true;
}