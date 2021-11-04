// Recursive
class Solution {
public:
    void solve(vector<vector<char> >& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = '_';
                }
            }
        }
        //Flood FIll on boundaries
        
        // 1st row
        for(int i = 0; i < n; i++){
            if(board[0][i] == '_'){
                Flood_fill(board,0,i);
            }
        }

        for(int i = 0; i < m; i++){
            if(board[i][n - 1] == '_'){
                Flood_fill(board,i,n - 1);
            }
        }

        for(int i = 0; i < n; i++){
            if(board[m - 1][i] == '_'){
                Flood_fill(board,m - 1,i);
            }
        }

        for(int i = 0; i < m; i++){
            if(board[i][0] == '_'){
                Flood_fill(board,i,0);
            }
        }
        
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == '_'){
                    board[i][j] = 'X';
                }
            }
        }
        
    }
    void Flood_fill(vector<vector<char> >& board, int i, int j){
        int m = board.size();
        int n = board[0].size();
        if(i < 0 || j < 0 || i >= m || j >= n){
            return ;
        }if(board[i][j] != '_'){
            return ;
        }
        board[i][j] = 'O';
        Flood_fill(board,i + 1,j);
        Flood_fill(board,i - 1,j);
        Flood_fill(board,i,j + 1);
        Flood_fill(board,i,j - 1);
        return;
    }
};
