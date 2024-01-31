class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        
        // since we need to calculate the distance for every pair of nodes so we need 2-D vector
        vector<vector<int>> distance(n + 1, vector<int>(n + 1, 1e9));
        
        // Now all the nodes which are directly connected they are having a distance 1 between them
        for (auto it : edges) {
            int u = it[0], v = it[1];
            distance[u][v] = 1;
            distance[v][u] = 1;
        }
        // answer array (using 0-based indexing)
        vector<int> ans(n-1, 0);
        
        // floyd-warshall
        for (int k = 1;k <= n;k++) {
            for (int i = 1;i <= n;i++) {
                for (int j = 1;j <= n;j++) {
                    distance[i][j] = min(distance[i][k] + distance[k][j], distance[i][j]);
                }
            }
        }
        
        
        // generating all subsets
        
        for (int i = 0;i < (1 << n);i++) { 
            vector<int> nodes;
            for (int j = 0;j < n;j++) {
                if (i & (1 << j)) {
                    nodes.push_back(j + 1);// storing the nodes
                }
            }
            
        
            
            int mx = -1, countEdges = 0;
            // going for each pair of nodes
            for (int k = 0;k < (int) nodes.size();k++) {
                for (int l = k + 1;l < (int) nodes.size();l++) {
                    // if distance between them is 1 it simply means they are connected by an edge.
                    if (distance[nodes[k]][nodes[l]] == 1) 
                    {
                        countEdges++;
                    }
                    // storing the maximum distance between each pair of nodes
                    mx = max(mx, distance[nodes[k]][nodes[l]]);
                }
            }
            
            // if number of edges == number of nodes - 1 => it is tree(basic definition of a tree)
            if (countEdges == (int) nodes.size() - 1 && mx > 0) { 
                // mx > 0 becoz there can be set of 1 node or 0 node as well, such set won't be contributing to answer
                ans[mx-1]++; // storing the count of each maxDistance. using 0-based indexing (mx - 1)
            }
        }
        
        return ans;
    }
};