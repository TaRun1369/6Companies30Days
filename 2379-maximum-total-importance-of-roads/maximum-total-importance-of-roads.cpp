class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long ans = 0;
        
         vector<long long> deg(n, 0);
        for (auto &a : roads) {
            deg[a[0]]++;
            deg[a[1]]++;
        }
        sort(deg.begin(), deg.end());
        for (long long i=0;i<n;i++) {
            ans += ( (i+1)*deg[i] );
        }
        return ans;
    }
};