class Solution {
public:
    int recur(int i,int j,string &w1,string &w2,vector<vector<int>> &dp){
        //base case 
        if(i < 0 && j< 0){
            // if(w1[i] == w2[j]) return 0;
             return 0;
        }
        if(j < 0){
            return i+1; 
        }
        if(i < 0){
            return j + 1;
        }
        if(w1[i] == w2[j]) return recur(i-1,j-1,w1,w2,dp);

        if(dp[i][j] != -1) return dp[i][j];

        // insert 
        int inse = 1 + recur(i,j-1,w1,w2,dp);
        int dele = 1 + recur(i - 1,j,w1,w2,dp);
        int repla = 1 + recur(i-1,j-1,w1,w2,dp); 

        return dp[i][j] = min({inse,dele,repla});
    }
    int minDistance(string word1, string word2) {
        if(word1 == word2) return 0;
        if(word1.size() < word2.size()) return minDistance(word2,word1);
        int n = word1.size(),m = word2.size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        if(n == 0) return m;
        if(m == 0) return n;
        
        return recur(n-1,m-1,word1,word2,dp);
    }
};