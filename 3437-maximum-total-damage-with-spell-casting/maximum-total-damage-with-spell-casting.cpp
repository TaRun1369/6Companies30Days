class Solution {
public:
map<int,int> mp;
    long long recur(vector<int> &p,int ind,vector<long long> &dp){
        if(ind == p.size()) return 0;
        if(dp[ind] != -1) return dp[ind];
        long long take = INT_MIN;
        long long nottake = recur(p,ind+1,dp);
        int nextIndex = ind + 1;
        while (nextIndex < p.size() && p[nextIndex] - p[ind] <= 2) {
            nextIndex++;
        }
    
        take = 1ll*mp[p[ind]]*p[ind] + recur(p,nextIndex,dp);
            // cout<<"take - "<<take<<endl;
        // }
        return dp[ind]=  max(take,nottake);
    }
    long long maximumTotalDamage(vector<int>& power) {

        int n = power.size();
        vector<long long> dp (n + 1,-1); 
        sort(power.begin(),power.end());
        vector<int> up;
        for(auto it : power) mp[it] ++;
        for(auto it : mp){
            up.push_back(it.first);
        }
        return recur(up,0,dp);

    }
};