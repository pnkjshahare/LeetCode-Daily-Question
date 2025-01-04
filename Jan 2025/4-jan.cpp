// Problem No : 1930. Unique Length-3 Palindromic Subsequences
// Problem Link : https://leetcode.com/problems/unique-length-3-palindromic-subsequences/description/?envType=daily-question&envId=2025-01-04
// solution :

class Solution
{
public:
    bool checkPalindrome(string str)
    {
        if (str[0] != str[2])
        {
            return false;
        }
        return true;
    }
    int countPalindromicSubsequence(string s)
    {
        int count = 0;
        set<string> st;
        for (int i = 0; i < s.size() - 2; i++)
        {
            for (int j = i + 1; j < s.size() - 1; j++)
            {
                for (int k = j + 1; k < s.size(); k++)
                {
                    string demo = "";
                    demo += s[i];
                    demo += s[j];
                    demo += s[k];
                    st.insert(demo);
                }
            }
        }
        for (auto it : st)
        {
            if (checkPalindrome(it))
            {
                count++;
            }
        }
        return count;
    }
};

// optimization
class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {
        int n = s.length();
        vector<int> first(26, -1), last(26, -1);
        unordered_set<string> uniquePalindromes;

        // Track the first and last occurrence of each character
        for (int i = 0; i < n; ++i)
        {
            if (first[s[i] - 'a'] == -1)
            {
                first[s[i] - 'a'] = i;
            }
            last[s[i] - 'a'] = i;
        }

        // Identify palindromic subsequences
        for (int i = 0; i < 26; ++i)
        {
            if (first[i] != -1 && last[i] != -1 && first[i] < last[i])
            {
                unordered_set<char> middleChars;
                for (int j = first[i] + 1; j < last[i]; ++j)
                {
                    middleChars.insert(s[j]);
                }
                for (char c : middleChars)
                {
                    uniquePalindromes.insert(string(1, 'a' + i) + c + string(1, 'a' + i));
                }
            }
        }

        return uniquePalindromes.size();
    }
};