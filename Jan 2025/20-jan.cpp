// Problem No :2661
// Problem Name :First Completely Painted Row or Column
// Solution :

// brute Force :
class Solution
{
public:
    bool checkRow(int col, vector<vector<int>> &mat)
    {
        for (int i = 0; i < mat.size(); i++)
        {
            if (mat[i][col] != -1)
            {
                return false;
            }
        }
        return true;
    }
    bool checkCol(int row, vector<vector<int>> &mat)
    {
        for (int i = 0; i < mat[0].size(); i++)
        {
            if (mat[row][i] != -1)
            {
                return false;
            }
        }
        return true;
    }
    int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
    {
        int rowSize = mat.size();
        int colSize = mat[0].size();
        for (int i = 0; i < arr.size(); i++)
        {
            int paintRow;
            int paintCol;
            for (int row = 0; row < rowSize; row++)
            {
                for (int col = 0; col < colSize; col++)
                {
                    if (mat[row][col] == arr[i])
                    {
                        mat[row][col] = -1;
                        paintRow = row;
                        paintCol = col;
                        break;
                    }
                }
            }
            if (checkRow(paintCol, mat) || checkCol(paintRow, mat))
            {
                return i;
            }
        }
        return -1;
    }
};

// Optimal :

class Solution
{
public:
    int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        // Map each matrix element to its row and column
        vector<pair<int, int>> mpp(n * m + 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                mpp[mat[i][j]] = {i, j};
            }
        }

        // Track counts for rows and columns
        vector<int> row(n, 0);
        vector<int> col(m, 0);

        // Process the sequence
        for (int i = 0; i < arr.size(); i++)
        {
            int r = mpp[arr[i]].first;
            int c = mpp[arr[i]].second;
            row[r]++;
            col[c]++;
            if (row[r] == m || col[c] == n)
            {
                return i;
            }
        }

        return 0;
    }
};