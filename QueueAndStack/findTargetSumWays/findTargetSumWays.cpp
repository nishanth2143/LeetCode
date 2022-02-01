#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution{
    list<int> SIGNS = {1, -1};

    int DFS(vector<int>& nums, int index, int target, int sum, int* expressionCount){
        if(index == nums.size()){
            if(sum == target){
                *expressionCount = *expressionCount + 1;
            }
                
            return 0;
        }

        DFS(nums, index+1, target, sum + nums[index], expressionCount);
        DFS(nums, index+1, target, sum + nums[index]*-1, expressionCount);

        return *expressionCount;
    }

    public:
        int findTargetSumWays(vector<int>& nums, int target, bool usingDFS){
            if(usingDFS){
                int expressionCount = 0;
                DFS(nums, 0, target, 0, &expressionCount);

                return expressionCount;
            }
            else{
                int sum = 0;
                if(nums.size() == 1 && nums[0] != abs(target))
                    return 0;
                
                for(int i=0; i<nums.size(); i++)
                    sum+= nums[i];
                
                if((sum + target) % 2 != 0)
                    return 0;

                target = (sum + target)/2;
                int rowCount = nums.size();
                int colCount = target;
                int V[rowCount+1][colCount+1];
                for(int i=0; i<=rowCount; i++){
                    for(int w=0; w<=colCount; w++){
                        if(i==0 && w==0)
                            V[i][w] = 1;
                        else if(i==0)
                            V[i][w] = 0;
                        else if(w - nums[i-1] >= 0)
                            V[i][w] = V[i-1][w] + V[i-1][w-nums[i-1]];
                        else
                            V[i][w] = V[i-1][w];
                        cout<<V[i][w]<<"\t";
                    }
                    cout<<endl;
                }

                return V[rowCount][colCount];

            }
            
        }
};

int main(){
    vector<int> nums = {7, 9, 3, 8, 0, 2, 4, 8, 3, 9};
    int target = 0;
    Solution* soln = new Solution();
    cout<<soln->findTargetSumWays(nums, target, false);

    return 0;
}