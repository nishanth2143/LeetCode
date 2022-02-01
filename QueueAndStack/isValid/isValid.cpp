#include <iostream>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

class Solution {
    list<char> OPENBRACKETS = {'{', '[', '('};
    list<char> CLOSINGBRACKETS = {'}', ']', ')'};

    char getClosingBracket(char c){
        switch(c){
            case '{':
                return '}';
            case '[':
                return ']';
            case '(':
                return ')';
        }

        return ' ';
    }

    public:
        bool isValid(string s){
            stack<char> stackData;
            for(int i=0; i<s.length(); i++){
                /* If current character is open bracket, then just push into stack. */
                if(find(OPENBRACKETS.begin(), OPENBRACKETS.end(), s[i]) != OPENBRACKETS.end()){
                    stackData.push(s[i]);
                }
                else{
                    if(stackData.empty())
                        return false;
                    char lastInserted = stackData.top();
                    if(s[i] == getClosingBracket(lastInserted)){
                        stackData.pop();
                        continue;
                    }
                    else{
                        return false;
                    }
                }
            }

            if(!stackData.empty())
                return false;

            return true;
        }
};

int main(){
    string s = "([)]";
    Solution* soln = new Solution();
    cout<<soln->isValid(s);

    return 0;
}