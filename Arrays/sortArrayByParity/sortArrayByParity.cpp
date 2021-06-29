#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
        vector<int> sortArrayByParity(vector<int>& nums){
            short i = 0, j = 1, length = nums.size();
            
            while(j < length){
                if(nums[i]%2 != 0){
                    if(nums[j]%2 == 0){
                        nums[i] = nums[i] + nums[j]; /* 3 + 6 = 9 */
                        nums[j] = nums[i] - nums[j]; /* 9 - 6 = 3 */
                        nums[i] = nums[i] - nums[j]; /* 9 - 3 = 6 */
                        i++;
                    }
                }else{
                    i++; 
                }
                j++;
            }

            return nums;
        }
};

int main()
{
    vector<int> nums;
    int x;
    for(int i = 0; i < 4; i++){
        cout<<"Enter "<<std::to_string(i+1)<<" value:";
        cin>> x;
        nums.push_back(x);
    }

    Solution* soln = new Solution();
    nums = soln->sortArrayByParity(nums);
    cout<<"New Array"<<endl;
    for(int i=0; i < nums.size(); i++){
        cout<<nums[i]<<endl;
    }

    return 0;
}