//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++



class dsu{
    
    public:
    vector<int> parent,rank,size;
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
    bool isValid(int r,int c,int n,int m){
        return r >= 0 &&c >= 0 && r < n && c < m;
    }
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        dsu d(n*m);
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1){
                    int dx[] = {1,0,-1,0};
                    int dy[] = {0,1,0,-1};
                    for(int k = 0;k < 4;k++){
                        int adjr = i + dx[k];
                        int adjc = j + dy[k];
                        if(isValid(adjr,adjc,n,m)){
                            if(grid[adjr][adjc] == 1){
                            int t1 = i*m + j;
                            int adjt =  adjr*m + adjc;
                            d.unionbySize(t1,adjt);
                            }
                        }
                    }
                }
            }
        }
        
        int maxi = 0;
        for(auto it : d.size){
            // cout<<it<<" ";
            maxi = max(maxi,it);
        }
        // cout<<endl;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 0){
                    int dx[] = {1,0,-1,0};
                    int dy[] = {0,1,0,-1};
                    int ans = 0;
                    set<int> s;
                    for(int k = 0;k < 4;k++){
                        int adjr = i + dx[k];
                        int adjc = j + dy[k];
                        if(isValid(adjr,adjc,n,m) && grid[adjr][adjc] == 1){
                            int adjt =  adjr*m + adjc;
                            int ulp = d.findUPar(adjt);
                            // cout<<ulp<<"        lod  "<<ans<<endl;
                            if(s.find(ulp) == s.end())
                            ans += d.size[ulp];
                            s.insert(ulp);
                            
                            
                        }
                        
                    }
                    maxi = max(maxi,ans + 1);
                }
            }
        }
        return maxi;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends