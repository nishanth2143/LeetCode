#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
        int dominantIndex(vector<int>& nums){
            if(nums.size() == 1)
                return 0;
            if(nums.size() == 2)
                return nums[1] >= 2*nums[0] ? 1 : (nums[0] >= 2* nums[1] ? 0 : -1);
            unsigned char largest = 0, secondLargest = 0, largestNoIndex = -1;
            for(unsigned char i=0; i<nums.size(); i++){
                if(nums[i] >= largest){
                    secondLargest = largest;
                    largest = nums[i];                    
                    largestNoIndex = i;
                }
                else if(nums[i] > secondLargest)
                    secondLargest = nums[i];

            }
            if(largest >= secondLargest*2)
                return largestNoIndex;
            
            return -1;
        }
};

int main(){
    Solution* soln = new Solution();
    vector<int> nums{3,6,1,0};

    cout<<"Index: "<<soln->dominantIndex(nums);
    return 0;
}