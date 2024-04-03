class Solution {
public:
    bool dfs(int i,int j,int n,int m,vector<vector<char>>& board, string word,int ind){
        if(ind==word.size())return true;
        if(i<0 || i>=n || j<0 || j>=m||word[ind]!=board[i][j])return false;
        
        // if(word[ind]==board[i][j]){
            char ch=board[i][j];
            board[i][j]='%';
        bool a=dfs(i-1,j,n,m,board,word,ind+1);
        bool b=dfs(i+1,j,n,m,board,word,ind+1);
        bool c=dfs(i,j+1,n,m,board,word,ind+1);
        bool d=dfs(i,j-1,n,m,board,word,ind+1);
            board[i][j]=ch;
        // }
        return a||b||c||d;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dfs(i,j,n,m,board,word,0))return true;
            }
        }
        return false;
    }
};