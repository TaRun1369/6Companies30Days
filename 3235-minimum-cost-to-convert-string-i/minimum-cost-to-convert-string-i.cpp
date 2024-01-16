class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>>dp(26,vector<int>(26,INT_MAX));
        int n = cost.size();
        for(int i = 0;i<26;i++){
            dp[i][i] = 0;
        }
        for(int i = 0;i<n;i++){
            dp[original[i]-'a'][changed[i]-'a'] = min(cost[i],dp[original[i]-'a'][changed[i]-'a']);
        }
        for(int k = 0;k<26;k++){
            for(int i = 0;i<26;i++){
                for(int j = 0;j<26;j++){
                    if(dp[i][k] != INT_MAX && dp[k][j] != INT_MAX){
                        dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
                    }
                }
            }
        }
        int m = target.length();
        long long ans = 0;
        for(int i = 0;i<m;i++){
            if(target[i] != source[i]){
                if(dp[source[i]-'a'][target[i]-'a'] == INT_MAX){
                    ans = -1;
                    break;
                }else{
                    ans+=dp[source[i]-'a'][target[i]-'a'];
                }
            }
        }
        return ans;
    }
};