#include <iostream>

using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        int carry_over = 0;
        string c = "";
        for (int i = a.length() - 1, j = b.length() - 1; i >= 0 || j >= 0; i--, j--)
        {
            if (i < 0)
                carry_over = (int)b[j] + carry_over - 48;
            else if (j < 0)
                carry_over = (int)a[i] + carry_over - 48;
            else
                carry_over = (int)a[i] + (int)b[j] + carry_over - 96;
            
            c = (carry_over % 2 == 0 ? '0' : '1') + c;
            carry_over = carry_over >= 2 ? 1 : 0;
        }

        if (carry_over != 0)
            c = '1' + c;

        return c;
    }
};

int main()
{
    Solution *soln = new Solution();
    string output = soln->addBinary("11", "1");

    return 0;
}