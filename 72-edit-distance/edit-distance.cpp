class Solution {
public:
    int recur(int i,int j,string &w1,string &w2,vector<vector<int>> &dp){
        //base case 
        
        if(j == 0){
            return i; 
        }
        if(i == 0){
            return j;
        }
       
        if(dp[i][j] != -1) return dp[i][j];

        // insert 
        int inse = 1 + recur(i,j-1,w1,w2,dp);
        int dele = 1 + recur(i - 1,j,w1,w2,dp);
        int repla = 1 + recur(i-1,j-1,w1,w2,dp); 

        return dp[i][j] = min({inse,dele,repla});
    }
    int minDistance(string w1, string w2) {
        // if(w1 == w2) return 0;
        // if(w1.size() < w2.size()) return minDistance(w2,w1);
        int n = w1.size(),m = w2.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        // if(n == 0) return m;
        // if(m == 0) return n;
        for(int i = 0;i<=n;i++) dp[i][0] = i;
        for(int j = 0;j<=m;j++) dp[0][j] = j;

        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                        
                        if(w1[i - 1] == w2[j - 1])  dp[i][j] = dp[i -1][j-1];
                        else{
                        int inse =  dp[i][j-1];
                        int dele =  dp[i - 1][j];
                        int repla =  dp[i-1][j-1]; 

                         dp[i][j] = 1 + min({inse,dele,repla});
                        }
            }
        }
        return dp[n][m];
        // return recur(n,m,word1,word2,dp);
    }
};