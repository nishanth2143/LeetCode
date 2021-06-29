#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
        int findMaxConsecutiveOnes(vector<int>& nums){
            int maxOnes = 0, currentOnes = 0;
            for(auto i = nums.begin(); i != nums.end(); ++i)
            {
                if(*i == 1){
                    currentOnes++;
                }
                else if(currentOnes > maxOnes){
                    maxOnes = currentOnes;
                    currentOnes = 0;
                }
                else {
                    currentOnes = 0;
                }
            }
            if(currentOnes > maxOnes){
                maxOnes = currentOnes;
            }

            return maxOnes;
        }
};

int main(){
    vector<int> nums;
    int x;
    for(int i = 0; i < 10; i++){
        cout<<"Enter "<<std::to_string(i+1)<<" value:";
        cin>> x;
        nums.push_back(x);
    }

    Solution* soln = new Solution();
    int maxConsecutiveOnes = soln->findMaxConsecutiveOnes(nums);

    cout<<"The max consecutive ones in entered data is: "<<std::to_string(maxConsecutiveOnes)<<endl;

    return 0;
}