class Solution
{
  public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum)
    {
        vector<int> ans;
        if (array.size() < 2)
            return ans;

        int k = 0;
        while (k < array.size() && array[k] < sum)
        {
            k++;
        }
        array.resize(k + 1);

        int minDot = sum * sum;
        for (int i = 0; i < array.size() - 1; i++)
        {
            int a = array[i];
            int b = sum - a;
            for (int j = i + 1; j < array.size(); j++)
            {
                if (b == array[j] && a * b < minDot)
                {
                    if (ans.empty())
                        ans.resize(2);
                    ans[0] = a;
                    ans[1] = b;
                    minDot = a * b;
                }
            }
        }

        return ans;
    }
};