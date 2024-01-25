class Solution {
public:
    string w1, w2;
    int n, m;
    vector<vector<int>> dp;
    int lcs(int i, int j){
        if (i>=n|| j>=m) return 0;
        if (dp[i][j]!=-1) return dp[i][j];
        if (w1[i]==w2[j]) return dp[i][j]=1+lcs(i+1, j+1);
        else return dp[i][j]=max(lcs(i+1, j), lcs(i, j+1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        w1=text1;
        w2=text2;
        n=text1.size();
        m=text2.size();
        dp.assign(n, vector(m, -1));
        return lcs(0, 0);
    }
};