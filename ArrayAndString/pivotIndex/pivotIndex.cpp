#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
        int pivotIndex(vector<int>& nums){
            bool isStrictlyIncreasing = true;
            int sum = 0, sumTillLastIndex = 0;
            for(int i=0; i<nums.size(); i++){
                if(i> 0 && abs(nums[i-1]) >= abs(nums[i])){
                    isStrictlyIncreasing = false;
                }
                sum = sum + nums[i];
            }
            if(isStrictlyIncreasing)
                return -1;
            for(int i=0; i< nums.size(); i++){
                int diff = sum-nums[i];
                if(diff % 2 == 0 && sumTillLastIndex == diff/2){
                    return i;
                }
                sumTillLastIndex = sumTillLastIndex + nums[i];
            }

            return -1;
        }
};

int main(){
    vector<int> nums{1,7,3,6,5,6};
    Solution* soln = new Solution();
    int index = soln->pivotIndex(nums);
    cout<<"Pivot Index: "<<index;

    return 0;
}