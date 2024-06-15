//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class dsu{
    public:
    vector<int > parent,rank,size;
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

    void unionbyRank(long long u,long long v){
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


class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        // vector<vector<int>> edges;        
        dsu ds(V);
        for(int i = 0;i<V;i++){
            for(int j = i+1;j<V;j++){
                if(adj[i][j] == 1)
                // edges.push_back({i,j});
                ds.unionbyRank(i,j);
            }
        }
        

         unordered_set<int> s;
        for(int i = 0;i<V;i++){
            // cout<<<<endl;
            s.insert(ds.findUPar(i));
        }
       
    
    return s.size();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends