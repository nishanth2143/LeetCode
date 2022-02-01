#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
        // bool validMountainArray(vector<int>& arr){
        //     bool isIncreasing = false, isDecreasing = false;
        //     for(int i = 1; i < arr.size(); i++){
        //         if(arr[i - 1] == arr[i])
        //             return false;
        //         if(arr[i-1] < arr[i]){
        //             if(!isDecreasing)
        //                 isIncreasing = true;
        //             else
        //                 return false;                    
        //         }
        //         else{
        //             if(isIncreasing)
        //                 isDecreasing = true;
        //             else
        //                 return false;
        //         }
        //     }
        //     if(isIncreasing && isDecreasing)
        //         return true;
        //     return false;
        // }

        bool validMountainArray(vector<int>& arr){
            int length = arr.size();
            if(length < 3)
                return false;
            int i = 1;
            while(i < length && arr[i - 1] < arr[i]) i++;
            if(i == length || i == 1)
                return false;
            while(i < length && arr[i-1] > arr[i]) i++;

            return i == length;
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
    bool isValid = soln->validMountainArray(nums);
    cout<<isValid;

    return 0;
}