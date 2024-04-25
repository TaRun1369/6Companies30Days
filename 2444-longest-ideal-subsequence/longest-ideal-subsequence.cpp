class Solution {
public:
    int recur(string &s,int k,int ind,int prev, vector<vector<int>> &dp){
        // cout<<"ind "<<ind<<endl;
        if(ind == 0){
             if(prev == -1 || abs((s[ind]-'a') - prev) <= k ){
                return 1;
             }
             else return 0;
        }
        if(dp[ind][prev + 1] != -1) return dp[ind][prev+1];
        int take = 0;
        if(prev == -1 || abs((s[ind]-'a') - prev) <= k ){
           take = 1 + recur(s,k,ind-1,(s[ind] - 'a'),dp);
        }
        int nottake = recur(s,k,ind-1,prev,dp);
        // cout<<"ind "<<ind<<endl;
        // cout<<take<<" - take and nottake - "<<nottake<<endl;
        return   dp[ind][prev+1] = max(take,nottake);
    }
    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int> (27,-1));
        return recur(s,k,n-1,-1,dp);
    }
};