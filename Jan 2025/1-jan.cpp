// Problem No :1422
// Problem Name : Maximum Score After Splitting a String
// Solution :
class Solution
{
public:
    int maxScore(string s)
    {
        int cntOne = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
            {
                cntOne++;
            }
        }
        int zero = 0;
        int maxi = 0;
        int one = 0;
        for (int i = 0; i < s.size() - 1; i++)
        {
            if (s[i] == '1')
            {
                one++;
            }
            if (s[i] == '0')
            {
                zero++;
            }
            maxi = max(maxi, zero + (cntOne - one));
        }
        return maxi;
    }
};