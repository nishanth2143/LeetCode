#include <iostream>
#include <vector>

using namespace std;

class Solution{
    // private:
    //     void removeAtIndex(vector<int>& nums, int index, int len){
    //         for(int i = index + 1; i < len; i++){
    //             nums[i-1] = nums[i];
    //         }
    //     }

    // public:
    //     int removeElement(vector<int>& nums, int val){
    //         int len = nums.size();
    //         for(int i = 0; i < len; i++){
    //             if(nums[i] == val){
    //                 removeAtIndex(nums, i, len);
    //                 len--;
    //                 i--;
    //             }
    //         }

    //         return len;
    //     }

    // public:
    //     int removeElement(vector<int>& nums, int val){
    //         int newLength = nums.size();
    //         for(int x : nums){
    //             if(x == val)
    //                 newLength--;
    //         }            

    //         int j = newLength - 1;
    //         int i = 0;
    //         while(i < newLength  && j < nums.size()){
    //             if(nums[i] == val){
    //                 if(nums[j] == val){
    //                     j++;
    //                     continue;
    //                 }else{
    //                     nums[i] = nums[j];
    //                     nums[j] = val;
    //                     j++;
    //                 }
    //             }
    //             i++;
    //         }

    //         return newLength;
    //     }

    public:
        int removeElement(vector<int>& nums, int val){
            char count = 0;
            unsigned char length = nums.size();
            char last = length - 1;
            for(char i = length - 1; i >=0; --i){
                if(nums[i] == val){
                    nums[i] = nums[last];
                    nums[last] = val;
                    last--;
                    count++;
                }
            }

            return length - count;
        }
        
};

int main(){
    vector<int> nums;
    int x, itemToRemove;
    for(int i = 0; i < 4; i++){
        cout<<"Enter "<<std::to_string(i+1)<<" value:";
        cin>> x;
        nums.push_back(x);
    }

    cout<<"Enter item to remove"<<endl;
    cin>>itemToRemove;

    Solution* soln = new Solution();
    int len = soln->removeElement(nums, itemToRemove);
    cout<<"New Array"<<endl;
    for(int i=0; i < len; i++){
        cout<<nums[i]<<endl;
    }

    return 0;
}