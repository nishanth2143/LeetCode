#include <iostream>
#include <vector>

using namespace std;

class Solution{

    public:
        vector<int> findDisappearedNumbers(vector<int>& nums){
            vector<int> resultSet;
            for(int i=1; i<= nums.size(); i++){
                int val = abs(nums[i-1]) - 1;
                if(val >= 0 && nums[val] > 0)
                    nums[val] = -nums[val];
            }
            for(int i = 0; i< nums.size(); i++){
                if(nums[i] > 0)
                    resultSet.push_back((i+1));
            }

            return resultSet;
        }
};

int main(){
    vector<int> nums;
    int x;
    for(int i = 0; i < 2; i++){
        cout<<"Enter "<<std::to_string(i+1)<<" value:";
        cin>> x;
        nums.push_back(x);
    }

    Solution* soln = new Solution();
    nums = soln->findDisappearedNumbers(nums);
    cout<<"Result Set"<<endl;
    for(auto x : nums){
        cout<<x<<endl;
    }

    return 0;
}