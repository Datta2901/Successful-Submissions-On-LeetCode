class Solution {
public:
    bool isValid(vector<vector<char> > &board,int row,int col,char a){
    int m = board.size();
    int n = board[0].size();
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            // Checking in row
            if(board[row][j] == a){
                return false;
            }
            // Checking in column
            if(board[i][col] == a){
                return false;
            }

            // Checking in subarray
            int r = (row / 3) * 3 + (i / 3);
            int c = (col / 3) * 3 + (i % 3);
            if(board[r][c] == a){
                return false;
            }
        }
    }
    return true;
}

    bool solve(vector<vector<char> > &board){
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == '.'){
                    for(char a = '1'; a <= '9'; a++){
                        if(isValid(board,i,j,a)){
                            board[i][j] = a;
                            if(solve(board)){
                                return true;
                            }else{
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};