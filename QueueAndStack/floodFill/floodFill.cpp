#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
    list<pair<int, int>> DIRECTIONS = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void BFS(vector<vector<int>> &image, int rowCount, int colCount, int rowNo, int colNo, int newColor)
    {
        queue<int> queueData;
        int targetColor = image[rowNo][colNo];
        queueData.push(rowNo * colCount + colNo);
        image[rowNo][colNo] = newColor;

        while (!queueData.empty())
        {
            int index = queueData.front();
            queueData.pop();
            int row = index / colCount;
            int col = index % colCount;
            for (pair<int, int> value : DIRECTIONS)
            {
                int x = row + value.first;
                int y = col + value.second;
                if (x >= 0 && x < rowCount && y >= 0 && y < colCount && image[x][y] == targetColor)
                {
                    image[x][y] = newColor;
                    queueData.push(x * colCount + y);
                }
            }
        }        
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        if(newColor == image[sr][sc])
            return image;
        
        BFS(image, image.size(), image[0].size(), sr, sc, newColor);

        return image;
    }
};

int main()
{
    vector<vector<int>> grid{{0, 0, 0}, {0, 1, 1}};
    Solution *soln = new Solution();
    grid = soln->floodFill(grid, 1, 1, 1);

    return 0;
}