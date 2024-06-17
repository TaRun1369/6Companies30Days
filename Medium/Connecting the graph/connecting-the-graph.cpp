//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++




class dsu{
    public:
    vector<long long> parent,rank,size;
    public:
    dsu(long long n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(long long i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    
    long long findUPar(long long node){
        if(node == parent[node]){
            return node;
        }
        return parent[node]=findUPar(parent[node]); // path compression
    }

    void unionByRank(long long u,long long v){
        long long ulp_u =  findUPar(u);

        long long ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            // koi bhi bann sakta 
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++; 
        }
    }



     void unionbySize(long long u,long long v){
        long long ulp_u =  findUPar(u);

        long long ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        
        else{
            // koi bhi bann sakta 
            parent[ulp_v] = ulp_u;
            size[ulp_u]+=size[ulp_v]; 
        }
    }


};

// 7 - 4 , 2 , 9 , 
// 3 - 1


class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        dsu d (n);
        int extra =0;
        // vector<int> vis(n,0);
        
        for(auto it : edge){
            if(d.findUPar(it[0]) == d.findUPar(it[1])){
                // break it
                extra++;
            }
            else{
                d.unionByRank(it[0],it[1]);
                // vis[it[0]] = 1;
                // vis[it[1]] = 1;
            }
        }
        int l = 0;
        for(int i = 0;i<n;i++){
            if( i == d.parent[i]) l++;
        }
        
        // l--;
        int ans = l - 1;
        // no. of edge required
        if(extra >= ans) return ans;
        else return -1;
        
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends