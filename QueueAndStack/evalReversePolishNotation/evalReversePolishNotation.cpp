#include <iostream>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

class Solution{
    list<string> OPERATORS = {"+", "-", "*", "/"};

    int doCalculation(int first, int second, string operand){
        if(operand == "+")
            return first + second;
        if(operand == "-")
            return first - second;
        if(operand == "*")
            return first * second;
        if(operand == "/")
            return first / second;
        
        return 0;
    }

    public:
        int evalReversePolishNotation(vector<string>& tokens){
            stack<int> sData;
            for(int i = 0; i< tokens.size(); i++){
                if(find(OPERATORS.begin(), OPERATORS.end(), tokens[i]) == OPERATORS.end()){
                    sData.push(stoi(tokens[i]));
                }
                else{
                    int second = sData.top(); sData.pop();
                    int first = sData.top(); sData.pop();
                    sData.push(doCalculation(first, second, tokens[i]));
                }
            }

            return sData.top();
        }
};

int main(){
    Solution* soln = new Solution();
    vector<string> tokens {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};

    cout<<"Result is: "<<soln->evalReversePolishNotation(tokens);

    return 0;
}