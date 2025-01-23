// Problem No :2429
// Problem Name:  Minimize XOR
// Solution :

class Solution
{
public:
    int betSet(string num)
    {
        int count = 0;
        for (int i = 0; i < num.size(); i++)
        {
            if (num[i] == '1')
            {
                count++;
            }
        }
        return count;
    }
    int minimizeXor(int num1, int num2)
    {
        int ones = __builtin_popcount(num2);
        int ans = 0;

        for (int i = 31; i >= 0 && ones > 0; i--)
        {
            if ((num1 >> i) & 1 != 0)
            {
                ans += pow(2, i);
                ones--;
            }
        }

        int k = 0;

        while (ones > 0)
        {
            if ((num1 >> k) & 1 != 0)
            {
                k++;
                continue;
            }

            else
            {
                ans += pow(2, k);
                ones--;
                k++;
            }
        }
        return ans;
    }
};