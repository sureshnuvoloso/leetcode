#include <stack>

class Solution {
    public:
        bool isValid(string s) {

            unordered_map<char, char> cmap;
            unordered_map<char, bool> open_cmap;
            cmap[')'] = '(';
            cmap['}'] = '{';
            cmap[']'] = '[';

            open_cmap['('] = true;
            open_cmap['{'] = true;
            open_cmap['['] = true;

            stack<char> stk;

            for (char c: s)
            {

                if (open_cmap[c])
                {
                    stk.push(c);
                }
                else //closing bracket
                {
                    // the stack top must be the opening bracket

                    if (stk.empty())
                    {
                        return false;
                    }
                    char c1= stk.top();

                    if (cmap[c] != c1)
                    {
                        return false;
                    }
                    stk.pop();
                }


            }

            return stk.empty();


        }
};
