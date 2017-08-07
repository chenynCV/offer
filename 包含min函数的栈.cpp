#include <vector>

class Solution
{
  public:
    void push(int value)
    {
        stack.push_back(value);
    }
    void pop()
    {
        stack.pop_back();
    }
    int top()
    {
        return stack[stack.size()-1];
    }
    int min()
    {
        int min = stack[0];
        for (int i = 1; i < stack.size(); i++)
        {
            if (min > stack[i])
                min = stack[i];
        }
        return min;
    }

    vector<int> stack;
};