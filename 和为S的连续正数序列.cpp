class Solution
{
  public:
    vector<vector<int>> FindContinuousSequence(int sum)
    {
        vector<vector<int>> ans;

        if (sum <= 1)
            return ans;

        int i = 1, j = 2;
        int sumNow = i + j;
        while (j < (sum >> 1) + 2 && i < j)
        {
            if (sumNow > sum)
            {
                sumNow -= i;
                i++;
            }
            else if (sumNow < sum)
            {
                j++;
                sumNow += j;
            }
            else
            {
                vector<int> tmp;
                for (int k = i; k <= j; k++)
                {
                    tmp.push_back(k);
                }
                ans.push_back(tmp);

                j++;
                sumNow += j;
            }
        }

        return ans;
    }
};