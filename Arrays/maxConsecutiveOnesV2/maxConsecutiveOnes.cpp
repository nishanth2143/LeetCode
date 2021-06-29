#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
        int findConsecutiveOnes(vector<int>& nums){
            int i, j = 0, zeros = 0, ret = 0;
            for(i = 0; i< nums.size(); i++){
                if(nums[i] == 0)
                    zeros++;
                
                while(j<=i && zeros > 1){
                    if(nums[j] == 0)
                        zeros--;
                    j++;
                }

                ret = max(ret, i-j+1);
            }

            return ret;
        }
};

int main(){
    vector<int> nums;
    int x;
    for(int i = 0; i < 6; i++){
        cout<<"Enter "<<std::to_string(i+1)<<" value:";
        cin>> x;
        nums.push_back(x);
    }

    Solution* soln = new Solution();
    int maxConsecutiveOnes = soln->findConsecutiveOnes(nums);

    cout<<"The max consecutive ones in entered data is: "<<std::to_string(maxConsecutiveOnes)<<endl;

    return 0;
}