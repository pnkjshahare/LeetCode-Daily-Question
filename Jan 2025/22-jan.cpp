// Problem Name :Map of Highest Peak
// Problem No :1765
// Solution :
class Solution
{
public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {
        int n = isWater.size();
        int m = isWater[0].size();
        queue<pair<int, int>> que;
        vector<vector<int>> height(n, vector<int>(m, -1));

        // Initialize water cells
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (isWater[i][j] == 1)
                {
                    height[i][j] = 0;
                    que.push({i, j});
                }
            }
        }

        // Direction arrays for neighbors
        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, 1, 0, -1};

        // BFS to calculate heights
        while (!que.empty())
        {
            int row = que.front().first;
            int col = que.front().second;
            que.pop();

            for (int i = 0; i < 4; i++)
            {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && height[newRow][newCol] == -1)
                {
                    height[newRow][newCol] = height[row][col] + 1;
                    que.push({newRow, newCol});
                }
            }
        }

        return height;
    }
};