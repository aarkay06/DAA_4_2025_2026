
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void reverseStack(stack<int> &stk)
    {
        if (stk.empty())
            return;
        int val = stk.top();
        stk.pop();
        reverseStack(stk);
        add_to_end_of_stack(stk, val);
    }

    void add_to_end_of_stack(stack<int> &stk, int val)
    {
        if (stk.empty())
        {
            stk.push(val);
            return;
        }
        int top = stk.top();
        stk.pop();
        add_to_end_of_stack(stk, val);
        stk.push(top);
    }
};
