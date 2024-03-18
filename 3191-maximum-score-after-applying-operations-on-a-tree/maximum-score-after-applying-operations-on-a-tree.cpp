class Solution {
public:
    long long dfs(int start, vector<vector<int> > &mp,vector<int> &vis,vector<int> &values){
        vis[start] = 1;

        long long mini = 0;
        for(auto it : mp[start]){
            if(!vis[it])
            mini += dfs(it,mp,vis,values);
        }

        if(mini == 0){
            return (long long)values[start];
        }

        return min((long long )values[start],mini);
    }
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();
        vector<vector<int>> mp(n);
        for(auto it : edges){
            int u = it[0], v = it[1];
            mp[u].push_back(v);
             mp[v].push_back(u);
        }
        long long total = accumulate(values.begin(),values.end(),0ll);
        vector<int> vis(n,0);
        long long leftout =  dfs(0,mp,vis,values);
        return total - leftout;
    }
};