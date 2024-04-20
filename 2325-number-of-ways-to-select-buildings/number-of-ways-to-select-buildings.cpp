class Solution {
private: 
	long long dp[100003][3][4];

    long long solve(string& s, int idx, int prev, int len, int n) {
        if(len == 3) return 1;
        if(idx == n) {
            return 0;
        }
        if(dp[idx][prev][len] != -1) return dp[idx][prev][len];

        long long res = solve(s, idx+1, prev, len, n);

        if(prev != (s[idx]-'0')) {
            res += solve(s, idx+1, s[idx]-'0', len+1, n);
        }
        return dp[idx][prev][len] = res;
    }

public:    
    
    long long numberOfWays(string s) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, 2, 0, n);
    }
};