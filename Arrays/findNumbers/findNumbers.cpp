#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
        int findNumbers(vector<int>& nums){
            int ans = 0;
            for(int i=0;i<nums.size();++i)
            {
                string temp=to_string(nums[i]);
                if(temp.length()%2==0)
                {
                    ans++;
                }
            }
            return ans;
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
    int evenNoOfDigitsCount = soln->findNumbers(nums);

    cout<<"Count of numbers having even number of digits is: "<<std::to_string(evenNoOfDigitsCount)<<endl;

    return 0;
}