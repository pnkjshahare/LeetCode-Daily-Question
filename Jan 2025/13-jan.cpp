// Problem No: 3223
// Problem Name : Minimum Length of String After Operations
// Solution:

class Solution
{
public:
    int minimumLength(string s)
    {
        map<char, int> mpp; // Frequency map to store counts of characters
        for (int i = 0; i < s.size(); i++)
        {
            mpp[s[i]]++; // Count frequency of each character
        }

        int StringLength = 0;
        for (auto it : mpp)
        {
            // If frequency is even, contribute +2
            if (it.second % 2 == 0)
            {
                StringLength += 2;
            }
            // If frequency is odd, contribute +1
            else
            {
                StringLength += 1;
            }
        }
        return StringLength; // Return the computed minimum length
    }
};