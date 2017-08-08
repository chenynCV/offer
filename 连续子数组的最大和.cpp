class Solution
{
  public:
    int FindGreatestSumOfSubArray(vector<int> array)
    {
        if (array.empty())
            return 0;

        int sumMax = array[0], sumNow = array[0];
        for (int i = 1; i < array.size(); i++)
        {
            sumNow = sumNow <= 0 ? array[i] : sumNow + array[i];
            sumMax = max(sumMax, sumNow);
        }

        return sumMax;
    }
};