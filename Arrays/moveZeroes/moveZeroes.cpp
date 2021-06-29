#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
        // void moveZeroes(vector<int>& nums){
        //     int i = 0, j = 1, length = nums.size();
        //     while(j < length){
        //         if(nums[i] == 0){
        //             if(nums[j] != 0){
        //                 nums[i] = nums[j];
        //                 nums[j] = 0;
        //                 i++;
        //             }
        //         }else{
        //             i++;
        //         }
        //         j++;
        //     }
        // }

        void moveZeroes(vector<int>& nums){
            int pos = 0;
            for(int i = 0; i< nums.size(); i++){
                if(nums[i] != 0){
                    nums[pos++] = nums[i];
                }
            }
            for(;pos<nums.size(); pos++){
                nums[pos] = 0;
            }
        }
};

int main()
{
    vector<int> nums;
    int x;
    for(int i = 0; i < 6; i++){
        cout<<"Enter "<<std::to_string(i+1)<<" value:";
        cin>> x;
        nums.push_back(x);
    }

    Solution* soln = new Solution();
    soln->moveZeroes(nums);
    cout<<"New Array"<<endl;
    for(int i=0; i < nums.size(); i++){
        cout<<nums[i]<<endl;
    }

    return 0;
}