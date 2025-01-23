// Problem Name :Construct K Palindrome Strings
// Problem No :1400
// Solution :

bool canConstruct(string s, int k)
{
    int n = s.size();
    if (n < k)
    {
        return false;
    }
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[s[i]]++;
    }
    int oddCount = 0;
    for (auto it : mpp)
    {
        if (it.second > 0 && it.second % 2 != 0)
        {
            oddCount++;
        }
    }
    if (oddCount > k)
    {
        return false;
    }
    return true;
}