int mod = 1e9 + 7;
class Solution {
public:

    long long recur(int ind,int ed , int k, vector<vector<int>> &dp){
        if(k == 0 && ind == ed){
            return 1;
        }
        if(k < 0 ){
            return 0;
        }
        if(dp[999+ind][k] != -1){
            return dp[999+ind][k];
        }

        return dp[999+ind][k] = (recur(ind + 1,ed,k-1,dp)%mod + recur(ind - 1,ed,k-1,dp)%mod);


    }
    int numberOfWays(int startPos, int endPos, int k) {
         vector<vector<int>> dp(3000,vector<int> (k+1,-1));
        
        return recur(startPos,endPos,k,dp)%mod;
    }
};