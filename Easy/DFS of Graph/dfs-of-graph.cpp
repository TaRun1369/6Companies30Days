//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
  public:
  
  void dfs(vector<int> &ans,int V,vector<int> adj[],int start,vector<int> &visited){
    //   if(visited[start] == 1){
    //       return;
    //   }
    //   cout<<"ye dala"<<start<<endl;
      ans.push_back(start);
       visited[start] = 1;
      for(auto it : adj[start]){
          if(!visited[it]){
              dfs(ans,V,adj,it,visited);
             
          } 
      }
      
      
  }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        vector<int> visited(V,0);
        for(int i = 0;i<V;i++){
            if(!visited[i])
                dfs(ans,V,adj,i,visited);
        }
        return ans;
    }
};




//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends