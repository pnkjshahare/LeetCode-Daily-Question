// Problem No : 2381. Shifting Letters II
// Solution :
// brute force
class Solution
{
public:
    string shiftingLetters(string s, vector<vector<int>> &shifts)
    {
        int n = shifts.size();
        for (int shift = 0; shift < n; shift++)
        {
            int first = shifts[shift][0];
            int last = shifts[shift][1];
            int pos = shifts[shift][2];
            if (pos == 1)
            {
                for (int i = first; i <= last; i++)
                {
                    int val = s[i];
                    val += 1;
                    if (val > 122)
                    {
                        val = 97;
                    }
                    s[i] = val;
                }
            }
            else
            {
                for (int i = first; i <= last; i++)
                {
                    int val = s[i];
                    val -= 1;
                    if (val < 97)
                    {
                        val = 122;
                    }
                    s[i] = val;
                }
            }
        }
        return s;
    }
};

//optimal

