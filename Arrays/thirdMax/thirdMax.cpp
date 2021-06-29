#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
        int thirdMax(vector<int>& nums){
            int* firstMax = nullptr;
            int* secondMax = nullptr;
            int* thirdMax = nullptr;

            for(int i = 0; i<nums.size(); i++){
                if(firstMax != nullptr && *firstMax == nums[i]){
                    continue;
                }
                else if(secondMax != nullptr && *secondMax == nums[i]){
                    continue;
                }
                else if(thirdMax != nullptr && *thirdMax == nums[i]){
                    continue;
                }

                if(firstMax == nullptr || nums[i] > *firstMax){
                    thirdMax = secondMax;
                    secondMax = firstMax;
                    firstMax = &nums[i];
                } else if(secondMax == nullptr || nums[i] > *secondMax){
                    thirdMax = secondMax;
                    secondMax = &nums[i];
                } else if(thirdMax == nullptr || nums[i] > *thirdMax) {
                    thirdMax = &nums[i];
                }
            }

            return thirdMax == nullptr ? *firstMax : *thirdMax;
        }
};

int main()
{
    vector<int> nums;
    int x;
    for(int i = 0; i < 3; i++){
        cout<<"Enter "<<std::to_string(i+1)<<" value:";
        cin>> x;
        nums.push_back(x);
    }

    Solution* soln = new Solution();
    int count = soln->thirdMax(nums);
    cout<<count<<endl;

    return 0;
}