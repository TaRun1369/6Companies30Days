

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long ans = 0;

        vector<int> degree(n, 0);

        for(auto it : roads){
            degree[it[0]]++;
            degree[it[1]]++;
        }

        vector<pair<int,int>> v;
        for(int i = 0; i < n; i++){
            v.push_back({degree[i], i});
        }

        sort(v.rbegin(), v.rend());

        vector<int> importance(n);
        for(int i = 0; i < n; i++){
            importance[v[i].second] = n - i;
        }

        for(auto it : roads){
            ans += importance[it[0]] + importance[it[1]];
        }

        return ans;
    }
};
