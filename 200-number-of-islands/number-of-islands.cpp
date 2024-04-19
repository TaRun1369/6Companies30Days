class Solution {
public:
    vector<int> di = {1,0,-1,0},dj = {0,1,0,-1};
    bool out(int i,int j,int n,int m){
        if(i < 0 || j< 0 || i >= n || j >= m) return true;
        return false;
    }
    void bfs(vector<vector<char>>& grid,int i ,int j){
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        grid[i][j] = '0';
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            int ci = t.first;
            int cj = t.second;
            for(int k =0;k<4;k++){
                if(!out(ci+di[k],cj+dj[k],n,m) && grid[ci+di[k]][cj+dj[k]] == '1'){
                    q.push({ci+di[k],cj+dj[k]});
                    grid[ci+di[k]][cj+dj[k]] = '0';
                }
            }

        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    bfs(grid,i,j);
                }
            }
        }
        return cnt;
    }
};