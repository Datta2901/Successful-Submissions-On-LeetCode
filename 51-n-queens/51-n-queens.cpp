class Solution {
private:
    bool isSafe(vector<string>&board,int row,int col,int n){
        int r = row;
        int c = col;
        //upper diagonal         
        while(r >= 0 && c >= 0){
            if(board[r][c] == 'Q'){
                return false;
            }
            r--;
            c--;
        }
        r = row;
        c = col;
        // left side
        while(c >= 0){
            if(board[r][c] == 'Q'){
                return false;
            }
            c--;
        }
        r = row;
        c = col;
        // lower diagonal         
        while(r < n && c >= 0){
            if(board[r][c] == 'Q'){
                return false;
            }
            r++;
            c--;
        }
        return true;
    }

    void getAnswer(int col,int n,vector<string>&board){
        if(col == n){
            answer.push_back(board);
            return;
        }
        for(int row = 0; row < n; row++){
            if(isSafe(board,row,col,n)){
                board[row][col] = 'Q';
                getAnswer(col + 1,n,board);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string> > answer;
public:
    vector<vector<string> > solveNQueens(int n) {
        string a(n,'.');
        // vector<vector<string> > board(n,vector<string>(n,'.'));
        vector<string> board(n);
        for(int i = 0; i < n; i++){
            board[i] = a;
        }
        
        // for(auto it : board){
        //     for(auto j : it){
        //         cout << j << " ";
        //     }
        //     cout << endl;
        // }
        getAnswer(0,n,board);
        return answer;
    }
};
