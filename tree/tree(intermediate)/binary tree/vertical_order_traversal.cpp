void verticalOrder(Node *root)
{
    //Your code here
    map<int, vector<int>> mp;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto p = q.front();
        Node *curr = p.first;
        int hd = p.second;
        mp[hd].push_back(curr->data);
        q.pop();
        if (curr->left)
            q.push({curr->left, hd - 1});
        if (curr->right)
            q.push({curr->right, hd + 1});
    }
    for (auto itr = mp.begin(); itr != mp.end(); itr++)
    {
        for (x : itr->second)
        {
            cout << x << " ";
        }
    }
}
