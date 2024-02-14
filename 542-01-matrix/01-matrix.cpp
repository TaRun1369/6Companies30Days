class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
            int n = mat.size();
            int m = mat[0].size();
            vector<vector<int>> dist(n,vector<int>(m,1e9));
            vector<int> dx = {1,0,-1,0},dy = {0,1,0,-1};
            queue<pair<int,pair<int,int>>> q;
            for(int i = 0 ;i<n;i++){
                for(int j = 0;j<m;j++){
                    if(mat[i][j] == 0){
                        q.push({0,{i,j}});
                        dist[i][j] = 0;
                    }
                }
            }

            while(!q.empty()){
                pair<int,pair<int,int>> fron = q.front();
                q.pop();

                for(int i = 0;i<4;i++){
                    int nx = fron.second.first + dx[i];
                    int ny = fron.second.second + dy[i];
                    if(nx >= 0 && ny >= 0 && nx < n && ny <m && 
                    dist[nx][ny] > 1 + fron.first && mat[nx][ny] != 0 ){
                        dist[nx][ny] = 1 + fron.first;
                        q.push({dist[nx][ny],{nx,ny}});
                    }
                 }
            }

            return dist;
    }
};