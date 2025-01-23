// Problem No :2657
// Problem Name :Find the Prefix Common Array of Two Arrays
// Solution :
vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
{
    int n = A.size();
    vector<int> freq(n + 1, 0);
    vector<int> ans;
    int common = 0;

    for (int i = 0; i < n; i++)
    {
        if (++freq[A[i]] == 2)
            common++;
        if (++freq[B[i]] == 2)
            common++;
        ans.push_back(common);
    }
    return ans;
}