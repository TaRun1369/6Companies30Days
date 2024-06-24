class Solution {
public:
    vector<int> kitnalagega;
    int recur(int ind,int inversionkitna, vector<vector<int>> &dp){
        if(ind <= 0){
            if(inversionkitna == 0){
                return 1;
            }
            else return 0;
        }

        if(kitnalagega[ind] != -1){
            if(kitnalagega[ind] != inversionkitna) return 0;
        }

        if(dp[ind][inversionkitna] != -1) return dp[ind][inversionkitna];

            int ans = 0;
        for (int i = 0;i<=min(inversionkitna,ind);i++){
            ans += recur(ind -1,inversionkitna - i,dp);
            ans %= ((int)(1e9 + 7));
        }

        return dp[ind][inversionkitna] =  ans;
    }
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        kitnalagega.resize(n,-1);

        for(auto it : requirements){
            kitnalagega[it[0]] = it[1];

        }
        vector<vector<int>> dp(301,vector<int>(401,-1));
        return recur(n-1,kitnalagega[n-1],dp);
    }
};