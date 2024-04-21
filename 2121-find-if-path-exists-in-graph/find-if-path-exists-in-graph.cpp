class Solution {
public:
    void dfs(bool &lund,vector<vector<int>> &adj,int src,int dest,vector<int> &visited){
        visited[src] = 1;
        if(src == dest){ 
        lund = true;
        return;
        }
        for(auto it : adj[src]){
            if(!visited[it]){
                if(it == dest){
                     lund = true;
                    return;
                } 
                dfs(lund,adj,it,dest,visited);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int dest) {
        bool lund=  false;
        vector<vector<int>> adj(n);

        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        dfs(lund,adj,source,dest,vis);
        return lund;
    }
};