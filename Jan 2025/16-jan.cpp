// problem No :2425
// Problem Name : Bitwise XOR of All Pairings
// Solution :
class Solution
{
public:
    int xorAllNums(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        int ans = 0;
        if (n % 2 != 0)
        {
            for (int i = 0; i < m; i++)
            {
                ans ^= nums2[i];
            }
        }
        if (m % 2 != 0)
        {
            for (int i = 0; i < n; i++)
            {
                ans ^= nums1[i];
            }
        }
        return ans;
    }
};