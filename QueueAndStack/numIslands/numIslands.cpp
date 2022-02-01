#include <iostream>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    list<pair<int, int>> DIRECTIONS = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void fillWithWater(vector<vector<char>> &grid, int rowCount, int columnCount, int rowNo, int colNo)
    {
        queue<int> queueData;
        queueData.push(rowNo * columnCount + colNo);
        grid[rowNo][colNo] = '0';

        while (!queueData.empty())
        {
            int index = queueData.front();
            queueData.pop();
            int row = index / columnCount;
            int col = index % columnCount;

            for (pair<int, int> value : DIRECTIONS)
            {
                int x = row + value.first;
                int y = col + value.second;
                if (x >= 0 && x < rowCount && y >= 0 && y < columnCount && grid[x][y] == '1')
                {
                    queueData.push(x * columnCount + y);
                    grid[x][y] = '0';
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int noOfIslands = 0, rowCount = grid.size(), columnCount = grid[0].size();

        for (int i = 0; i < rowCount; i++)
        {
            for (int j = 0; j < columnCount; j++)
            {
                if (grid[i][j] == '1')
                {
                    noOfIslands++;
                    fillWithWater(grid, rowCount, columnCount, i, j);
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