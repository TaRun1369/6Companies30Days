class Solution {
public:
    // vector<int> dx = {1,0,-1,0},dy = {0,1,0,-1};
    void dfs(int &count,vector<vector<char>>& board,vector<vector<int>>& vis,int x,int y){
        if(x < 0 || y < 0|| x  >= board.size() || y >= board[0].size()|| vis[x][y]==1||  board[x][y] == '.'){
            return;
        }

        vis[x][y] = 1;
        dfs(count,board, vis, x+1,y);
        dfs(count,board, vis, x,y+1);
        dfs(count,board, vis, x-1,y);
        dfs(count,board, vis, x,y-1);
        
    }
    int countBattleships(vector<vector<char>>& board) {
        vector<vector<int>> vis(board.size(),vector<int>(board[0].size(),0));
        int count = 0;
        for(int i = 0;i<board.size();i++)
        {
            for(int j = 0; j<board[0].size();j++)
            {
                if(board[i][j] == 'X' and vis[i][j]==0)
                    {
                        dfs(count,board, vis, i,j);
                        count++;
                    }
            }
        }
        return count;
    }
};