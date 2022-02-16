

class Solution {
public:
    bool isValidSudoku(vector<vector<char> >& board){
        int m = board.size();
        int n = board[0].size();
        unordered_set<char>row[m],column[n],subArray[m / 3][n / 3];
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                char a = board[i][j];
                if(a != '.'){
                    if(row[i].count(a) || column[j].count(a) || subArray[i / 3][j / 3].count(a)){
                        return false;
                    }
                    row[i].insert(a);
                    column[j].insert(a);
                    subArray[i / 3][j / 3].insert(a);
                }
            }
        }
        return true;
    }
};