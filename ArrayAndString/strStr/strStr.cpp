#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution{

    void computeLPSArray(int lpsArray[], string pattern, int patternLength){
        lpsArray[0] = 0;
        int len=0, i=1;
        while(i < patternLength){
            if(pattern[i] == pattern[len]){
                lpsArray[i] = len+1;
                i++; len++;
            }else{
                if(len != 0){
                    len = lpsArray[len-1];
                }else{
                    lpsArray[i] = 0;
                    i++;                    
                }
            }
        }
    }

    int KMPSearch(string text, string pattern){        
        int lpsArray[pattern.length()];
        computeLPSArray(lpsArray, pattern, pattern.length());
        pattern = " "+pattern;
        int i=0, j=0;
        while(i < text.length()){
            if(j+1 == pattern.length())
                return i-j;
            if(text[i] == pattern[j+1]){
                i++; j++;
            } else if(j != 0){
                j = lpsArray[j-1];
            } else {
                i++;
            }
        }
        if(j+1 == pattern.length())
            return i-j;
        
        return -1;
    }

    public:
        int strStr(string haystack, string needle){
            if(needle.length() == 0 && haystack.length() == 0)
                return 0;

            if(needle.length() == 0)
                return 0;

            int val = KMPSearch(haystack, needle);

            return val;
            
        }
};

int main(){
    Solution* soln =  new Solution();
    cout<<"Index is: "<<soln->strStr("missisippi", "isippi")<<endl;

    return 0;
}