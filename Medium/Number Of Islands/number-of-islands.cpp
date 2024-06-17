//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++




class dsu{
    vector<long long> parent,rank,size;
    long long n1;
    public:
    dsu(long long n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(long long i=0;i<=n;i++){
            parent[i]=i;
        }
        n1 = n;
    }
    
    long long findUPar(long long node){
        if(node == parent[node]){
            return node;
        }
        return parent[node]=findUPar(parent[node]); // path compression
    }

    bool unionbyRank(long long u,long long v){
        long long ulp_u =  findUPar(u);

        long long ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return false;
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
         return true;
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

    long long kitneComponents(){
        long long ans =  0;
        for(int i = 0;i<n1;i++){
            if(i != parent[i]) ans++;
        }
        return ans;
    }
};


class Solution {
  public:
  bool isvalid(int r,int c,int n,int m){
      return r >= 0 && c >=0 && r < n && c < m;
  }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &o) {
        // code here
        // 1,0 - 5 , 1,1 - 6  (i * m + j) - har cell ka unique denotion
        // vector<vector<int>> vis(n,vector<int> (m,0));
        vector<int> vis(n*m,0);
        dsu d(n*m);
        vector<int> ans;
        int c = 0;
        for(auto it : o){
            int u = it[0];
            int f = 0;
            int v = it[1];
            int t = u * m + v;
            if(vis[t] == 1) {
                ans.push_back(c);
                continue;
            }
            vis[t] = 1;
            c++;
            // if(t % m !=  0 && vis[t-1] == 1){
            //     if(d.unionbyRank(t,t-1) == true) c--;
            // }
            
            // if((t - (m - 1)%m) !=  0 && vis[t + 1] == 1)
            // if(d.unionbyRank(t,t+1) == true) c--;
            
            // if( t - m >= 0 && vis[t - m] == 1)
            // if(d.unionbyRank(t,t-m) == true) c--;
            
            // if(t + m < m*n &&  vis[t + m] == 1)
            // if(d.unionbyRank(t,t+m) == true) c--;
            
            int dx[] = {0,1,0,-1};
            int dy[] = {1,0,-1,0};
            for(int i = 0;i<4;i++){
                int adjr = u + dx[i];
                int adjc = v + dy[i];
                int adjt = adjr * m + adjc;
                if(isvalid(adjr,adjc,n,m)){
                    if(vis[adjt] == 1){
                        if(d.unionbyRank(adjt,t) == true){
                            c--;
                        }
                    }
                }
            }
             
            ans.push_back(c);
            
        }
        
         // 0 1 0 1
         // 1 1 1 1
         
        
        
        return ans;
        
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends