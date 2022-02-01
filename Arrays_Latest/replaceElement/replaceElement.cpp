#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
        vector<int> replaceElements(vector<int>& arr){
            int length = arr.size();
            if(length == 0)
                return arr;
            if(length == 1){
                arr[0] = -1;
                return arr;
            }
            int currentLargest = arr[0];
            for(int i = 0; i < length - 2; i++){
                if(currentLargest == arr[i]){
                    int j = i+1;
                    currentLargest = arr[j++];
                    while(j < length){
                        if(currentLargest < arr[j]){
                            currentLargest = arr[j];
                        }
                        j++;
                    }
                }
                arr[i] = currentLargest;
            }

            arr[length-2] = arr[length-1];
            arr[length-1] = -1;

            return arr;
        }
};

int main()
{
    vector<int> nums;
    int x;
    for(int i = 0; i < 1; i++){
        cout<<"Enter "<<std::to_string(i+1)<<" value:";
        cin>> x;
        nums.push_back(x);
    }

    Solution* soln = new Solution();
    nums = soln->replaceElements(nums);
    for(int i=0; i < nums.size(); i++){
        cout<<nums[i]<<endl;
    }

    return 0;
}