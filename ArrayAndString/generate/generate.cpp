#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
        vector<vector<int>> generate(int numRows){
            vector<int> cRow;
            vector<int> pRow;
            vector<vector<int>> result;
            int start = 1;

            while(start <= numRows){
                if(start == 1)
                    cRow = {1};
                
                else{
                    pRow = cRow;
                    cRow = {};
                    cRow.push_back(1);
                    for(int i=0, j=1; j<pRow.size(); i++, j++){
                        cRow.push_back(pRow[i] + pRow[j]);
                    }
                    cRow.push_back(1);
                }
                result.push_back(cRow);
                start++;
            }

            return result;
        }
};

int main(){
    int numRows = 5;
    Solution* soln = new Solution();
    vector<vector<int>> result = soln->generate(numRows);

    return 0;
}