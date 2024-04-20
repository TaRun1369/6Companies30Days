class Solution {
public:
    void dfs(vector<vector<int>>& land,int i,int j, int &mi,int &mj,int n,int m){
        if(i < 0 || j < 0 || i >= n || j >= m || land[i][j] == 0){
            return;
        }
        mi = max(mi , i);
        mj = max(mj,j);
        land[i][j] = 0;
        // if(land[i][j] == 1){
            dfs(land,i+1,j,mi,mj,n,m);
            dfs(land,i-1,j,mi,mj,n,m);
            dfs(land,i,j+1,mi,mj,n,m);
            dfs(land,i,j-1,mi,mj,n,m);
        // }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();
        vector<vector<int>> ans;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(land[i][j] == 1){
                    cout<<i<<" lund "<<j<<endl;
                    int mi = 0,mj = 0;
                    dfs(land,i,j,mi,mj,n,m);
                    ans.push_back({i,j,mi,mj});
                }
            }
        }
        return ans;
    }
};