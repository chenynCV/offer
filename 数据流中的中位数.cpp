class Solution
{
  public:
    void Insert(int num)
    {
        if (qMax.empty() || num <= qMax.top())
        {
            qMax.push(num);
            if (qMax.size() - qMin.size() > 1)
            {
                qMin.push(qMax.top());
                qMax.pop();
            }
        }
        else
        {
            qMin.push(num);
            if (qMin.size() - qMax.size() > 1)
            {
                qMax.push(qMin.top());
                qMin.pop();
            }
        }
    }

    double GetMedian()
    {
        if (qMax.size() > qMin.size())
        {
            return qMax.top();
        }
        else if (qMax.size() < qMin.size())
        {
            return qMin.top();
        }
        else
        {
            return double(qMax.top() + qMin.top()) / 2.0;
        }
    }

    template <class T>
    using min_heap = priority_queue<T, std::vector<T>, std::greater<T>>;

    template <class T>
    using max_heap = priority_queue<T, std::vector<T>, std::less<T>>;

    max_heap<int> qMax;
    min_heap<int> qMin;
};