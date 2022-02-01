#include <iostream>
#include <vector>

using namespace std;

class Solution{    

    void burnTrees(vector<vector<int>>& forest, int row, int col, int rowCount, int colCount){
        //Exit condition
        if(row < 0 || row >= rowCount || col < 0 || col >= colCount || forest[row][col] != 1)
            return;
        
        forest[row][col] = -1;
        burnTrees(forest, row + 1, col, rowCount, colCount);
        burnTrees(forest, row - 1, col, rowCount, colCount);
        burnTrees(forest, row, col + 1, rowCount, colCount);
        burnTrees(forest, row, col - 1, rowCount, colCount);
    }

    public:
        void forestFire(vector<vector<int>>& forest, int startingRow, int startingCol){
            burnTrees(forest, startingRow,startingCol, forest.size(), forest[0].size());
        }       

};

int main(){
    vector<vector<int>> forest; int rowCount, colCount;
    cout<<"Enter row count"<<endl;
    cin>>rowCount;
    cout<<"Enter column count"<<endl;
    cin>>colCount;
    cout<<"Enter the matrix"<<endl;
    int temp;
    for(int i=0; i< rowCount; i++){
        vector<int> row;
        for(int j=0; j< colCount;j++){
            cin>>temp;
            row.push_back(temp);
        }
        forest.push_back(row);
    }

    int startingRow, startingCol;
    cout<<"Enter starting row"<<endl;
    cin>>startingRow;
    cout<<"Enter starting column"<<endl;
    cin>>startingCol;

    Solution* soln = new Solution();
    soln->forestFire(forest, startingRow, startingCol);

    for(int i=0; i< rowCount; i++){
        for(int j=0; j< colCount;j++){
            cout<<forest[i][j]<<"\t";
        }
        cout<<endl;
    }
    

    return 0;
}