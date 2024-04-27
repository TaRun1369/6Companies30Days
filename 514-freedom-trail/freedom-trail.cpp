class Solution {
public:
    int minii(int i,int ri,int n){
        int dist = abs(ri - i);
        int ulta = n - dist;

        return min(dist,ulta) ;
    }
    int recur(string &ring,string &key,int ri,int ki,vector<vector<int>> &dp){
        if(ki == key.size()) return 0;
        int take = INT_MAX;
        if(dp[ri][ki] != -1) return dp[ri][ki];
        for(int i = 0;i<ring.size();i++){
            if(ring[i] == key[ki]){
                take = min(take,1 + minii(i,ri,ring.size()) + recur(ring,key,i,ki + 1,dp));
            }
        }
        // nottake = recur(ring,key,ri,ki);
        return dp[ri][ki] = take;
    
    }
    int findRotateSteps(string ring, string key) {
        vector<vector<int>> dp(ring.size(),vector<int>(key.size(),-1));
        return recur(ring,key,0,0,dp);
    }
};