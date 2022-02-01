#include <iostream>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
    list<pair<int, int>> DIRECTIONS = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void DFS(vector<vector<char>> &grid, int rowCount, int colCount, int rowNo, int colNo)
    {
        if (rowNo < 0 || rowNo >= rowCount || colNo < 0 || colNo >= colCount || grid[rowNo][colNo] != '1')
            return;

        // update the land as water as it has been processed.
        grid[rowNo][colNo] = '0';

        for (pair<int, int> direction : DIRECTIONS)
        {
            DFS(grid, rowCount, colCount, rowNo + direction.first, colNo + direction.second);
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int rowCount = grid.size();
        int colCount = grid[0].size();
        int noOfIslands = 0;

        for (int i = 0; i < rowCount; i++)
        {
            for (int j = 0; j < colCount; j++)
            {
                if (grid[i][j] == '1')
                {
                    noOfIslands++;
                    // Process this island.
                    DFS(grid, rowCount, colCount, i, j);
                }
            }
        }

        return noOfIslands;
    }
};

int main()
{
    vector<vector<char>> grid{{'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}};
    Solution *soln = new Solution();
    int x = soln->numIslands(grid);

    cout << "No of islands is: " << x << endl;

    return 0;
}