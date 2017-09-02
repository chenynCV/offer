class Solution
{
  public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV)
    {
        stack<int> s;
        int i = 0, j = 0;
        for (i = 0; i < pushV.size(); i++)
        {
            s.push(pushV[i]);
            if (pushV[i] == popV[j])
            {
                s.pop();
                j++;
            }
        }

        while (!s.empty())
        {
            int v = s.top();
            s.pop();
            if (v == popV[j])
            {
                j++;
            }
        }
        return j >= popV.size();
    }
};