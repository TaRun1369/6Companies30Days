class Solution {
public:
    void dfs(int st,map<int,int> &v,map<int,vector<int>> &mp,vector<int> &ans){

        if(v.find(st) == v.end()){
            v[st] = 1;
            ans.push_back(st);
        }

        for(auto it : mp[st]){
            if(v.find(it) == v.end()){
                dfs(it,v,mp,ans);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& ap) {
        int siz = ap.size() + 1;
        map<int,vector<int>> adj;
        int s = ap[0][0];
        for(auto it : ap){
            
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        for(auto it : adj){
            if(it.second.size() == 1){
                s = it.first;
                break;
            }
        }
        map<int,int> vis;
        vector<int> ans;
        dfs(s,vis,adj,ans);
        return ans;
    }
};