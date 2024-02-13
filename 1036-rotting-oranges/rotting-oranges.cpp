class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // bfs
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int> ( m,0));
        vector<int> dx = {1,0,-1,0},dy = {0,1,0,-1};
        queue<vector<int>>q;
        for(int i = 0;i<n;i++){
            for(int j= 0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({0,i,j});
                    visited[i][j] = 2;
                }
            }
        }

        int ans = 0;
        while(!q.empty()){
            vector<int> t = q.front();
            q.pop();
            int time = t[0];
            int x = t[1];
            int y = t[2];
            ans = max(ans,time);
            for(int i = 0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >=0 && ny >=0 && nx < n && ny < m && visited[nx][ny]!=2 && grid[nx][ny] == 1){
                    q.push({time+1,nx,ny});
                    visited[nx][ny] = 2;

                }
            }
        }


        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visited[i][j]==0 && grid[i][j]==1)
                {
                    return -1;
                }
            }
        }

        return ans;
    }
};