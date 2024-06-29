class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<set<int> > ans(n);
        vector<int> indegree(n,0);
        vector<vector<int>> adj(n);
        queue<int> q;
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }

        for(int i = 0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int t = q.front();
            q.pop();

            for(auto it : adj[t]){
                for(auto kuch: ans[t]){
                    ans[it].insert(kuch);
                }
                cout<<"madar - "<<it<<" "<<t<<endl;
                ans[it].insert(t);
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }


        }

        // for(auto &it : ans){
        //     sort(it.begin(),it.end());
        // }
        vector<vector<int> > ans1(n);
        for(int i = 0;i<n;i++){
            for(auto it : ans[i]){
                ans1[i].push_back(it);
            }
        }
        // sort(ans.begin(),ans.end());
        return ans1;
    }
};