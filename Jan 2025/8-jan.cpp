// Problem No :(Leetcode 3042)
// Problem Name :Count Prefix and Suffix Pairs I
// Solution :
int countPrefixSuffixPairs(vector<string> &words)
{
    int n = words.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        string s1 = words[i];
        for (int j = i + 1; j < n; j++)
        {
            string s2 = words[j];
            if (s2.length() < s1.length())
            {
                continue;
            }
            string pre = s2.substr(0, s1.length());
            string suf = s2.substr(s2.length() - s1.length());
            if (pre == s1 && suf == s1)
            {
                count++;
            }
        }
    }
    return count;
}