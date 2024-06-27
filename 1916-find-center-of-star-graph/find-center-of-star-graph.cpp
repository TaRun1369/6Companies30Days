class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> degree(n+1,0);
        int ans;
        for(auto it : edges){
            degree[it[0] - 1]++;
            degree[it[1] - 1]++;
            if(degree[it[0] - 1] == n){
                ans = it[0];
            }
            if(degree[it[1] - 1] == n){
                ans = it[1];
            }
        }

        return ans;

    }
};