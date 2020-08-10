firstNonRepeating(char str[])
{
    unordered_map<char, int> mp;
    queue<char> q;

    for (int i = 0; i < n; ++i)
    {
        q.push(stream[i]);
        mp[stream[i]]++;
        while (!q.empty())
        {
            if (mp[q.front()] > 1)
            {
                q.pop();
            }
            else
            {
                cout << q.front() << " ";
                break;
            }
        }
        if (q.empty())
        {
            cout << "-1 ";
        }
    }
}