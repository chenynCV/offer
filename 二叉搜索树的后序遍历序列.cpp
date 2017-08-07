class Solution
{
  public:
    bool VerifySquenceOfBST(vector<int> sequence)
    {
        if (sequence.empty())
            return false;

        int root = sequence[sequence.size() - 1];
        vector<int> sequenceL, sequenceR;
        int maxL = -1, minR = sequence.size();
        for (int i = 0; i < sequence.size() - 1; i++)
        {
            if (sequence[i] < root)
            {
                sequenceL.push_back(sequence[i]);
                if (maxL < i)
                    maxL = i;
            }

            if (sequence[i] > root)
            {
                sequenceR.push_back(sequence[i]);
                if (minR > i)
                    minR = i;
            }
        }

        bool flag = minR > maxL;
        if(!sequenceL.empty())
            flag = flag & VerifySquenceOfBST(sequenceL);
        if(!sequenceR.empty())
            flag = flag & VerifySquenceOfBST(sequenceR);

        return flag;
    }
};