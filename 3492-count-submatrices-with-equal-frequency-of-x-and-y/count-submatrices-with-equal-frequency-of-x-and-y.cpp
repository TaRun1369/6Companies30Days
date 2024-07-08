class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int cx = 0,cy = 0;
        int n = grid.size();
        int m = grid[0].size();
        // cout<<n<<" "<<m<<endl;
        vector<pair<int,int>> precompute(n,{0,0});
        int ans = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                
                if(grid[j][i] == 'X') cx++;
                if(grid[j][i] == 'Y') cy++;
                if(precompute[j].first + cx == precompute[j].second + cy && precompute[j].first + cx != 0){ 
                    // cout<<i<<" "<<j<<endl;
                    ans++;}
                precompute[j].first += cx;
                precompute[j].second += cy;
            }
            cx = 0;
            cy = 0;

        }

        return ans;
    }
};