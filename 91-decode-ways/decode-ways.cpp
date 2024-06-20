class Solution {
public:
    int recur(string s,int ind,vector<int> &dp){
         if(s[ind] == '0') return 0;
        if(ind >= s.size() - 1) return 1;
       
        int take = 0;

        if(dp[ind] != -1) return dp[ind];
        if(s[ind] == '1'){
            take += recur(s,ind+1,dp);
            take += recur(s,ind+2,dp);
        }
        else if(s[ind] == '2'){
            if(s[ind + 1] <= '6' && s[ind + 1] >= '0') {
                take += recur(s,ind + 2,dp);
            }
            take += recur(s,ind+1,dp);
        }
        else{
            take += recur(s,ind+1,dp);
        }

        return dp[ind] = take;
    }
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        vector<int> dp(s.size() , -1);
        return recur(s,0,dp);
    }
};