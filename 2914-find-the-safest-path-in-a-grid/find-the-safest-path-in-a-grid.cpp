class Solution {
public:
        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,1,-1};
    bool check(int sf,vector<vector<int>> &dist){
        int n = dist.size();
        queue<pair<int,int>> q;
        q.push({0,0});
        vector<vector<int>> visited (dist.size(),vector<int> (dist.size(),0));
        visited[0][0] = 1;
         if(dist[0][0] < sf)
            return false;

        while(!q.empty()){
            auto t = q.front();
            q.pop();
            if(t.first == n - 1 && t.second == n-1){
                return true;
            }
            for(int i  = 0;i<4;i++){
                int ni = t.first + dx[i];
                int nj = t.second + dy[i];
                if(ni < 0 || nj < 0 || ni >= n || nj >= n || visited[ni][nj] == 1 || dist[ni][nj] <  sf){
                        continue;
                } 
                q.push({ni,nj});
                visited[ni][nj] = 1;

                
            }

        }
        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        
        int n = grid.size();
        queue<pair<int,int>> q;
        vector<vector<int>> dist (n,vector<int>(n,-1));
        vector<vector<int>> visited (n,vector<int>(n,0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    visited[i][j] = 1;
                }
            }
        }
        int lev = 0;
        while(!q.empty()){
            int siz = q.size();
            while(siz--){
                auto t = q.front();
                q.pop();
                dist[t.first][t.second] = lev;
                // visited[t.first][t.secon/d] = 1;
                for(int i = 0;i<4;i++){
                    int ni = t.first + dx[i];
                    int nj = t.second + dy[i];

                    if(ni < 0 || nj < 0 || ni >= n || nj >= n || visited[ni][nj] == 1){
                        continue;
                    } 
                    q.push({ni,nj});
                    visited[ni][nj] = 1;

                }
            }
            lev++;
        }



        int l = 1,r = 400,ans = 0;
        while(l <= r){
            int midsf = (l + r)/2;
            if(check(midsf,dist)){
                l = midsf + 1;
                ans = midsf;
            }
            else {
                r = midsf - 1;
            }
        }

        return ans;

        
    }
};