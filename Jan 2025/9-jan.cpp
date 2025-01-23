// Problem No :2185
// Problem Name : Counting Words With a Given Prefix
// Solution :
class Solution
{
public:
    int prefixCount(vector<string> &words, string pref)
    {
        int size = pref.size();
        int count = 0;
        for (int i = 0; i < words.size(); i++)
        {
            string demo = words[i];
            string demoPref = demo.substr(0, size);
            if (demoPref == pref)
            {
                count++;
            }
        }
        return count;
    }
};
