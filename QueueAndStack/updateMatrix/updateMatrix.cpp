#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
    list<pair<int, int>> DIRECTIONS = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void BFS(vector<vector<int>>& mat, int rowCount, int colCount){
        queue<pair<int, int>> queueData;
        for(int i=0; i<rowCount; i++){
            for(int j=0; j<colCount; j++){
                if(mat[i][j] == 0){
                    queueData.push({i, j});
                }else{
                    mat[i][j] = INT_MAX;
                }
            }
        }

        while(!queueData.empty()){
            pair<int, int> index = queueData.front();
            queueData.pop();
            for(pair<int, int> value : DIRECTIONS){
                int x = index.first + value.first;
                int y = index.second + value.second;
                if(x >= 0 && x<rowCount && y>=0 && y<colCount && mat[index.first][index.second] + 1 < mat[x][y]){
                    mat[x][y] = mat[index.first][index.second] + 1;
                    queueData.push({x, y});
                }
            }
        }
    }

public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int rowCount = mat.size();
        int colCount = mat[0].size();
        BFS(mat, rowCount, colCount);

        return mat;
    }
};