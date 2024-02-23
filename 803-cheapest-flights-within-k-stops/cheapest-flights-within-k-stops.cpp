class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& fl, int src, int dst, int k) {
        map<int,vector<pair<int,int>>>m;
        for(int i=0;i<fl.size();i++){
            m[fl[i][0]].push_back({fl[i][1],fl[i][2]});
        }
        int x=0;
        vector<int> dist(n, INT_MAX);
        queue<pair<int,int>>q;
        q.push({src,0});
        while(!q.empty() and x<=k){
            int s=q.size();
            while(s--){
                auto[node,cst]=q.front();
                q.pop();
                for(auto &[nbr,price]:m[node]){
                    if(cst+price<dist[nbr]){
                        dist[nbr]=cst+price;
                        q.push({nbr,dist[nbr]});
                    }
                }
            }
            x++;
        }
        return dist[dst]==INT_MAX ? -1 : dist[dst];
    }
};