#include <iostream>
#include <vector>

using namespace std;

class Solution{
    private:
        void Merge(vector<int>& left, vector<int>& right, vector<int>& expected){
            int leftCount = left.size();
            int rightCount = right.size();
            int i = 0, j = 0, k = 0;
            while(i < leftCount && j < rightCount){
                if(left[i] < right[j]){
                    expected[k] = left[i++];
                }else{
                    expected[k] = right[j++];
                }
                k++;
            }
            while(i < leftCount){
                expected[k++] = left[i++];
            }
            while(j < rightCount){
                expected[k++] = right[j++];
            }
        }

        void MergeSort(vector<int>& expected){
            int length = expected.size();
            if(length < 2)
                return;
            int mid = length/2;
            vector<int> left(mid);
            vector<int> right(length - mid);
            for(int i = 0; i< mid; i++)
                left[i] = expected[i];
            for(int i = mid; i < length; i++)
                right[i-mid] = expected[i];
            
            MergeSort(left); MergeSort(right);
            Merge(left, right, expected);            
        }
    
    public:
        int heightChecker(vector<int>& heights){
            vector<int> expected(heights);
            MergeSort(expected);
            int diffCount = 0;
            for(int i = 0; i< heights.size(); i++){
                if(heights[i] != expected[i])
                    diffCount++;
            }

            return diffCount;
        }
};

int main()
{
    vector<int> nums;
    int x;
    for(int i = 0; i < 5; i++){
        cout<<"Enter "<<std::to_string(i+1)<<" value:";
        cin>> x;
        nums.push_back(x);
    }

    Solution* soln = new Solution();
    int count = soln->heightChecker(nums);
    cout<<count<<endl;

    return 0;
}