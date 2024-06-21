class Solution {
public:
    int recur(vector<vector<int>> &t,int ind,int j,vector<vector<int>> &dp){
        if(ind == t.size() ) return 0;
        if(dp[ind][j] != -1) return dp[ind][j];
        int one = INT_MAX,two = INT_MAX;
            one = recur(t,ind + 1,j,dp);
            two = recur(t,ind+1,j +1,dp);

            return dp[ind][j] = t[ind][j] + min(one,two);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        return recur(triangle,0,0,dp);
    }
};