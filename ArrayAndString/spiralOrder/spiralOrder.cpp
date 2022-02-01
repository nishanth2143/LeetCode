#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution{

    bool isValidIndex(int row, int col, int topB, int bottomB, int rightB, int leftB){
        if(row < topB + 1 || row > bottomB - 1 || col < leftB + 1 || col > rightB - 1)
            return false;
        
        return true;
    }

    public:
        vector<int> spiralOrder(vector<vector<int>> & matrix){
            int row = 0, col = 0, rowCount = matrix.size()-1, colCount = matrix[0].size()-1;
            int topB = -1, bottomB = matrix.size(), rightB = matrix[0].size(), 
            leftB = -1; vector<int> output;
            char direction = 'r'; 
            while(isValidIndex(row, col, topB, bottomB, rightB, leftB)){
                output.push_back(matrix[row][col]);
                if(direction == 'r'){
                    if(col == rightB - 1){
                        direction = 'd'; row++; topB++;
                    }
                    else col++;                                       
                }
                else if(direction == 'l'){
                    if(col == leftB + 1){
                        direction = 't'; row--; bottomB--;
                    }
                    else col--;                    
                }
                else if(direction == 't'){
                    if(row == topB + 1){
                        direction = 'r'; col++; leftB++;
                    }
                    else row--;
                }
                else{
                    if(row == bottomB - 1){
                        direction = 'l'; col--; rightB--;
                    }
                    else row++;
                }                
            }

            return output;
        }
};

int main(){
    vector<vector<int>> matrix {{1, 2},{3, 4}};
    Solution* soln = new Solution();
    vector<int> output = soln->spiralOrder(matrix);
    for(int i=0; i<output.size(); i++)
        cout<<output[i]<<"\t";
    
    return 0;
}