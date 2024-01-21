class Solution
{
    int mod = 1e9 + 7, n, dp[16385][16];
    int rec(vector<int> &v, int cnt, int i, int mask)
    {
        if (cnt == n)
            return 1;
        if (dp[mask][i + 1] != -1)
            return dp[mask][i + 1];
        
        int res = 0;
        for (int j = 0; j < n; j++)
            if (i == -1 || ((mask & (1 << j)) == 0 && i != j && (v[i] % v[j] == 0 || v[j] % v[i] == 0)))
                (res += rec(v, cnt + 1, j, mask | (1 << j))) %= mod;
        return dp[mask][i + 1] = res;
    }

public:
    int specialPerm(vector<int> &v)
    {
        n = v.size();
        memset(dp, -1, sizeof(dp));
        return rec(v, 0, -1, 0);
    }
};