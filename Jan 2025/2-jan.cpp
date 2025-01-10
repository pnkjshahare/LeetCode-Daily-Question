// Problem No :2559 
// Problem Name :Count Vowel Strings in Ranges
// solution:
class Solution
{
public:
    bool checkVowel(char c)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
    {
        vector<int> v;
        for (auto &it : words)
        {
            if (checkVowel(it[0]) && checkVowel(it[it.size() - 1]))
            {
                v.push_back(1);
            }
            else
            {
                v.push_back(0);
            }
        }
        for (int i = 1; i < v.size(); i++)
        {
            v[i] = v[i - 1] + v[i];
        }
        vector<int> ans;
        for (auto &it : queries)
        {
            int left = it[0];
            int right = it[1];
            if (left == 0)
            {
                ans.push_back(v[right]);
            }
            else
            {
                ans.push_back(v[right] - v[left - 1]);
            }
        }
        return ans;
    }
};
