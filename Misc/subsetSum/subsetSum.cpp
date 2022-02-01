#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
        bool subsetSumExists(vector<int>& nums, int targetSum){   
            int rowCount = nums.size();
            int colCount = targetSum;         
            bool V[rowCount+1][colCount+1];
            for(int i=0; i<= rowCount; i++){
                for(int w=0; w<=colCount; w++){
                    if(w==0)
                        V[i][w] = true;
                    else if(i==0)
                        V[i][w] = false;
                    else if(w >= nums[i-1])
                        V[i][w] = V[i-1][w] || V[i-1][w - nums[i-1]];
                    else
                        V[i][w] = V[i-1][w];
                    cout<<V[i][w]<<"\t";
                }
                cout<<endl;
            }

            return V[rowCount][colCount];
        }
};

int main(){
    Solution* soln = new Solution();
    vector<int> nums {3, 4, 5, 8};
    int target = 10;
    cout<<soln->subsetSumExists(nums, target);

    return 0;
}