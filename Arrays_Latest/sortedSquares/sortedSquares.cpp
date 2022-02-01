#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
        vector<int> sortedSquares(vector<int>& nums){
            int j = 0;
            vector<int> sortedArray(nums.size());
            // for(j = 0; j < nums.size(); j++){
            //     if(nums[j] >= 0)
            //         break;
            // }
            // int i = j-1, k = 0;
            // while(i >= 0 && j < nums.size()){
            //     if((nums[i] * nums[i]) < (nums[j] * nums[j])){
            //         sortedArray.push_back(nums[i] * nums[i]);
            //         i--;
            //     }
            //     else{
            //         sortedArray.push_back(nums[j] * nums[j]);
            //         j++;
            //     }
            // }
            // while(i >= 0){
            //     sortedArray.push_back(nums[i] * nums[i]);
            //     i--;
            // }
            // while(j < nums.size()){
            //     sortedArray.push_back(nums[j] * nums[j]);
            //     j++;
            // }

            int left = 0, right = nums.size() - 1;
            for(int i = nums.size()-1; i>=0; --i){
                if(abs(nums[left]) > abs(nums[right])){
                    sortedArray[i] = nums[left] * nums[left];
                    left++;
                }
                else{
                    sortedArray[i] = nums[right] * nums[right];
                    right--;
                }
            }

            //Copy over to nums array to deallocate the space for sortedArray after function is out of scope.
            for(int i=0; i< nums.size(); i++)
                nums[i] = sortedArray[i];

            return nums;
        }
};

int main(){
    vector<int> nums;
    int x;
    for(int i = 0; i < 5; i++){
        cout<<"Enter "<<std::to_string(i+1)<<" value:";
        cin>> x;
        nums.push_back(x);
    }

    Solution* soln = new Solution();
    nums = soln->sortedSquares(nums);
    cout<<"Sorted Array"<<endl;
    for(auto x : nums){
        cout<<x<<endl;
    }

    return 0;
}