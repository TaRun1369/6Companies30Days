//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



// class dsu{
    
//     public:
//     map<long long,long long> parent,rank,size;
//     dsu(long long n){
//         // rank.resize(n+1,0);
//         // parent.resize(n+1);
//         // size.resize(n+1,1);
//         for(long long i=0;i<=n;i++){
//             parent[i]=i;
//             size[i] = 1;
//             rank[i] = 0;
//         }
//     }
    
//     long long findUPar(long long node){
//         if(node == parent[node]){
//             return node;
//         }
//         return parent[node]=findUPar(parent[node]); // path compression
//     }

//     void unionbyRank(long long u,long long v){
//         long long ulp_u =  findUPar(u);

//         long long ulp_v = findUPar(v);
//         if(ulp_u == ulp_v) return;
//         if(rank[ulp_u] < rank[ulp_v]){
//             parent[ulp_u] = ulp_v;
//         }
//         else if(rank[ulp_v] < rank[ulp_u]){
//             parent[ulp_v] = ulp_u;
//         }
//         else{
//             // koi bhi bann sakta 
//             parent[ulp_v] = ulp_u;
//             rank[ulp_u]++; 
//         }
//     }



//      void unionbySize(long long u,long long v){
//         long long ulp_u =  findUPar(u);

//         long long ulp_v = findUPar(v);
//         if(ulp_u == ulp_v) return;
//         if(size[ulp_u] < size[ulp_v]){
//             parent[ulp_u] = ulp_v;
//             size[ulp_v] += size[ulp_u];
//         }
        
//         else{
//             // koi bhi bann sakta 
//             parent[ulp_v] = ulp_u;
//             size[ulp_u]+=size[ulp_v]; 
//         }
//     }


// };


// class Solution {
//   public:
//     int maxRemove(vector<vector<int>>& s, int n) {
//         // Code here
//         // 1 0 0
//         // 1 0 0
//         // 0 1 1
        
      
//         dsu d(n);
//         for(int i = 0;i<n-1;i++){
//             for(int j = i+1;j<n;j++){
//                 vector<int> v1 = s[i],v2 = s[j];
//                 if(v1[0]==v2[0] || v1[1] == v2[1]){
//                     int t1 = (v1[0]* 10000   + v1[1]*100 ) ;
//                     int t2 = v2[0]* 10000  + v2[1]*100; 
//                     d.unionbySize(t1,t2);
//                 }
//             }
//         }
        
//         int ans = 0;
//         set<int> ss;
        
//         for(auto it : s){
//             int t = it[0] * 10000 + it[1]*100;
            
//                 int u = d.findUPar(t);
//                 if(ss.find(u) == ss.end())
//                 if(d.size[u] - 1 > 0) ans += (d.size[u] - 1);
                
//                 ss.insert(u);
            
//         }
//         return ans;
        
        
//     }
// };


class dsu {
public:
    map<long long, long long> parent, rank, size;
    
    long long findUPar(long long node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findUPar(parent[node]); // path compression
    }

    void unionbySize(long long u, long long v) {
        long long ulp_u = findUPar(u);
        long long ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

    void add(long long x) {
        if (parent.find(x) == parent.end()) {
            parent[x] = x;
            size[x] = 1;
            rank[x] = 0;
        }
    }
};

class Solution {
public:
    int maxRemove(vector<vector<int>>& s, int n) {
        dsu d;
        for (const auto& coord : s) {
            int row = coord[0], col = coord[1];
            int rowIdentifier = row + 10000; // Unique row identifier
            int colIdentifier = -col - 10000; // Unique column identifier
            
            d.add(rowIdentifier);
            d.add(colIdentifier);
            
            d.unionbySize(rowIdentifier, colIdentifier);
        }
        
        set<int> uniqueParents;
        for (const auto& coord : s) {
            int row = coord[0], col = coord[1];
            int rowIdentifier = row + 10000;
            int colIdentifier = -col - 10000;
            
            uniqueParents.insert(d.findUPar(rowIdentifier));
            uniqueParents.insert(d.findUPar(colIdentifier));
        }
        
        return n - uniqueParents.size();
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends