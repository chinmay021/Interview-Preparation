void topView(struct Node *root)
{
    if (root == NULL)
        return;
    map<int, int> mp;
    queue<pair<Node *, int>> q;
    int hd = 0;
    q.push(make_pair(root, hd));

    while (!q.empty())
    {
        pair<Node *, int> curr = q.front();
        q.pop();
        Node *temp = curr.first;
        int hd = curr.second;
        if (!mp[hd])
        {
            mp[hd] = temp->data;
        }

        if (temp->left)
            q.push(make_pair(temp->left, hd - 1));
        if (temp->right)
            q.push(make_pair(temp->right, hd + 1));
    }
    for (auto it = mp.begin(); it != mp.end(); it++)
        cout << it->second << " ";
}