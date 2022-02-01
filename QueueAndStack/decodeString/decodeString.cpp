#include <iostream>
#include <stack>

using namespace std;

class Solution
{

    string decodeString(string s, int itrCount)
    {
        string decodedString = "";
        for (int i = 0; i < itrCount; i++)
        {
            decodedString = s + decodedString;
        }

        return decodedString;
    }

public:
    string decodeString(string s)
    {
        stack<int> numStack;
        stack<string> valStack;
        string count;
        string unprocessedString;
        string output;

        for (int i = 0; i < s.length(); i++)
        {
            if (isdigit(s[i]))
            {
                count = count + s[i];
                if (unprocessedString != "")
                {
                    valStack.push(unprocessedString);
                    unprocessedString = "";
                }
            }
            else if (s[i] == '[')
            {
                valStack.push("[");
                numStack.push(stoi(count));
                count = "";
            }
            else if (s[i] == ']')
            {
                string totalUnprocessedString = "";
                while(unprocessedString != "["  && !valStack.empty()){
                    totalUnprocessedString = unprocessedString + totalUnprocessedString;
                    unprocessedString = valStack.top();
                    valStack.pop();
                }
                unprocessedString = "";
                valStack.push(decodeString(totalUnprocessedString, numStack.top()));
                numStack.pop();
            }
            else
            {
                unprocessedString = unprocessedString + s[i];
            }
        }

        while(!valStack.empty()){
            output = valStack.top() + output;
            valStack.pop();
        }
        if(unprocessedString != "")
            output = output + unprocessedString;

        return output;
    }
};

int main()
{
    Solution *soln = new Solution();
    string decodedString = soln->decodeString("100[leetcode]");
    cout << "Decoded String: " << decodedString;

    return 0;
}