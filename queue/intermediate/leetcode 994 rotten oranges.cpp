class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int minTime = 0;
        int fresh = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1)
                {
                    fresh++;
                }
            }
        }
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty())
        {
            int n = q.size();
            bool rotten = false;
            for (int i = 0; i < n; ++i)
            {
                pair<int, int> curr = q.front();
                q.pop();
                for (auto direction : directions)
                {
                    int i = curr.first + direction.first;
                    int j = curr.second + direction.second;
                    if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1)
                    {
                        grid[i][j] = 2;
                        q.push({i, j});
                        fresh--;
                        rotten = true;
                    }
                }
            }
            if (rotten)
            {
                minTime++;
            }
        }
        return fresh ? -1 : minTime;
    }
};