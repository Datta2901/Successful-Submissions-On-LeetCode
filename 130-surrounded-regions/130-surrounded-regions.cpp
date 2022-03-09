class Solution {
public:
    int m,n;
    void dfs(vector<vector<char> >&board,int i,int j){
        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O' ){
            return;
        }
        board[i][j] = '_';
        dfs(board,i,j + 1);
        dfs(board,i + 1,j);
        dfs(board,i - 1,j);
        dfs(board,i,j - 1);
    }
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if((i == 0 || j == n - 1 || j == 0 || i == m - 1) && (board[i][j] == 'O')){
                    dfs(board,i,j);
                }
            }
        }
       
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == '_'){
                    board[i][j] = 'O';
                }else{
                    board[i][j] = 'X';
                }
            }
        }
    }
};