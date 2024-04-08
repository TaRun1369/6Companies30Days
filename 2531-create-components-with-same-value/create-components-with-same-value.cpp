class Solution {
public:
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int n = nums.size();
        vector<vector<int>> adj(n);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        for(int i = n;i>=1;i--){
            if(sum % i != 0)continue;
            vector<int> weightvis(n);
            if(dfs(0,nums,adj,weightvis,sum/i) == 0) return i - 1;
        }

        return 0;
    }

    int dfs(int curr,vector<int> &nums,vector<vector<int>> &adj,vector<int> &vis,int target){
        vis[curr] = nums[curr];

        for(auto it : adj[curr]){
            if(vis[it] != 0) continue;

            vis[curr] += dfs(it,nums,adj,vis,target);

            if(vis[curr] > target) return 1e8;
        }
        if(vis[curr] == target) return 0;
        return vis[curr];
    }
};