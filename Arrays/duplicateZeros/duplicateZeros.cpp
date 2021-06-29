#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
        void duplicateZeros(vector<int>& arr){
            // for(int i = 0; i <= arr.size() - 2; i++){
            //     if(arr[i] == 0){
            //         int j = arr.size() - 2;
            //         while(j > i){
            //             arr[j+1] = arr[j];
            //             j--;
            //         }
            //         arr[i+1] = 0;
            //         i++;
            //     }
            // }

            int zeroesCount = 0;
            for(int value : arr){
                if(value == 0)
                    zeroesCount++;
            }
            int i = arr.size() - 1, j = arr.size() - 1 + zeroesCount;
            while(j > i){
                insert(arr, i, j--);
                if(arr[i] == 0){
                    insert(arr, i, j--);
                }
                i--;
            }
        }

        void insert(vector<int>& arr, int i, int j){
            if(j < arr.size()){
                arr[j] = arr[i];
            }
        }
};

int main(){
    vector<int> nums;
    int x;
    for(int i = 0; i < 8; i++){
        cout<<"Enter "<<std::to_string(i+1)<<" value:";
        cin>> x;
        nums.push_back(x);
    }

    Solution* soln = new Solution();
    soln->duplicateZeros(nums);
    cout<<"Duplicated Array:"<<endl;
    for(auto x : nums){
        cout<<x<<endl;
    }

    return 0;
}