#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
        vector<int> plusOne(vector<int>& digits){
            unsigned char size = digits.size();            
            if(digits[size-1] != 9){
                digits[size-1]++;
                return digits;
            }
            unsigned char carry_over = 0;
            for(unsigned char i=size-1; i!=255; i--){
                if(digits[i] == 9){
                    carry_over = 1;
                    digits[i]=0;
                }
                else{
                    digits[i] = digits[i] + carry_over;
                    carry_over = 0;
                    break;
                }
            }
            if(carry_over != 0)
                digits.insert(digits.begin(), 1);

            return digits;
        }
};

int main(){
    Solution* soln = new Solution();
    vector<int> digits{9};
    digits = soln->plusOne(digits);

    return 0;
}