#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
        bool checkIfExist(vector<int>& arr){
            if(arr.size() == 0 || arr.size() == 1){
                return false;
            }
            short i = 0, j = 1;
            while(i < arr.size() - 1){
                if(arr[i] == arr[j]*2 || arr[j] == arr[i]*2){
                    return true;
                }
                ++j;
                if(j == arr.size()){
                    j = ++i + 1;
                }
            }

            return false;
        }
};

int main()
{
    vector<int> nums = {1, 2, 3,4, 5};
    // int x;
    // for(int i = 0; i < 4; i++){
    //     cout<<"Enter "<<std::to_string(i+1)<<" value:";
    //     cin>> x;
    //     nums.push_back(x);
    // }

    Solution* soln = new Solution();
    bool isExists = soln->checkIfExist(nums);
    cout<<isExists;

    return 0;
}