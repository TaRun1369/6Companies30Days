class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<int> deg(n,0);
        queue<int> q;
        vector<int> ans;
        vector<vector<int>> adj(n);
        for(auto it : edges){
            adj[it[1]].push_back(it[0]);
            adj[it[0]].push_back(it[1]);
            deg[it[1]]++;
            deg[it[0]]++;
        }

        for(int i = 0;i<n;i++){
            if(deg[i] == 1) q.push(i);
        }
        while(n > 2){
            int siz = q.size();
            n -= siz;
            while(siz--){
                int f = q.front();
                q.pop();

                for(auto it : adj[f]){
                    deg[it]--;
                    if(deg[it] == 1) q.push(it);
                }
            }
            
        }

        while(!q.empty()) {ans.push_back(q.front());
        q.pop();
        }
        return ans;
    }
};