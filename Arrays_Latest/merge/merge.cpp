#include <iostream>
#include <vector>

using namespace std;

class Solution{

public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
        int i = m-1, j = n-1, k = m+n-1;

        while(i >= 0 && j >= 0){
            if(nums1[i] > nums2[j]){
                nums1[k] = nums1[i];
                i--;
            }
            else{
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
        while(i >= 0){
            nums1[k] = nums1[i];
            i--; k--;
        }
        while(j >= 0){
            nums1[k] = nums2[j];
            j--; k--;
        }
    }
};

int main(){
    vector<int> nums1, nums2;
    int x;
    for(int i = 0; i < 0; i++){
        cout<<"Enter "<<std::to_string(i+1)<<" value:";
        cin>> x;
        nums1.push_back(x);
    }

    for(int i = 0; i < 1; i++){
        cout<<"Enter "<<std::to_string(i+1)<<" value:";
        cin>> x;
        nums2.push_back(x);
    }

    Solution* soln = new Solution();
    soln->merge(nums1, 0, nums2, 1);
    cout<<"Sorted Array"<<endl;
    for(auto x : nums1){
        cout<<x<<endl;
    }

    return 0;
}