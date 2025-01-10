// Problem No :1769
// Problem Name :Minimum Number of Operations to Move All Balls to Each Box
// Solution :

// brute Force :
vector<int> minOperations(string boxes)
{
    vector<int> ans;
    for (int i = 0; i < boxes.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < boxes.size(); j++)
        {
            if (boxes[j] == '1' && i != j)
            {
                count += abs(j - i);
            }
        }
        ans.push_back(count);
    }
    return ans;
}

// Optimal Solution :
vector<int> minOperations(string boxes)
{
    int n = boxes.size();
    vector<int> res(n);
    int aheadBall = 0;
    int behindBall = 0;
    for (int i = 0; i < n; i++)
    {
        if (boxes[i] == '1')
        {
            res[0] += i;
            aheadBall++;
        }
    }
    if (boxes[0] == '1')
    {
        aheadBall--;
        behindBall++;
    }
    for (int i = 1; i < n; i++)
    {
        res[i] = res[i - 1] + behindBall - aheadBall;
        if (boxes[i] == '1')
        {
            aheadBall--;
            behindBall++;
        }
    }
    return res;
}