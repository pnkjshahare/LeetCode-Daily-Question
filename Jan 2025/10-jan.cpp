// Problem No :916
// Problem Name : Word Subsets
// Solution :

class Solution
{
public:
    bool checkSub(int arr1[], int arr[])
    {
        for (int i = 0; i < 26; i++)
        {
            if (arr1[i] < arr[i])
            {
                return false;
            }
        }
        return true;
    }
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        int Maxarr[26] = {0};
        for (int i = 0; i < words2.size(); i++)
        {
            int temp[26] = {0};
            string demo = words2[i];
            for (auto ch : demo)
            {
                temp[ch - 'a']++;
            }
            for (int i = 0; i < 26; i++)
            {
                Maxarr[i] = max(Maxarr[i], temp[i]);
            }
        }
        vector<string> ans;
        for (int i = 0; i < words1.size(); i++)
        {
            int arr1[26] = {0};
            string demo = words1[i];
            for (auto ch : demo)
            {
                arr1[ch - 'a']++;
            }
            if (checkSub(arr1, Maxarr))
            {
                ans.push_back(demo);
            }
        }
        return ans;
    }
};