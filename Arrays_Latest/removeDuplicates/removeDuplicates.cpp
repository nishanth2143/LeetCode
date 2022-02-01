#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
        int removeDuplicates(vector<int>& nums){
            int length = nums.size();
            if(length == 0 || length == 1){
                return length;
            }
            int i = 0, j = 1;
            while(j < length){
                if(nums[j] != nums[i]){
                    nums[++i] = nums[j];
                }
                j++;
            }

            return i+1;
        }
};

int main()
{
    vector<int> nums;
    int x;
    for(int i = 0; i < 10; i++){
        cout<<"Enter "<<std::to_string(i+1)<<" value:";
        cin>> x;
        nums.push_back(x);
    }

    Solution* soln = new Solution();
    int len = soln->removeDuplicates(nums);
    cout<<"New Array"<<endl;
    for(int i=0; i < len; i++){
        cout<<nums[i]<<endl;
    }

    return 0;
}