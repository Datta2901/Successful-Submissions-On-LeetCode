class Solution {
public:
    bool isValidSudoku(vector<vector<char> >& board){
        set<char> row[9];
        set<char> col[9];
        set<char> sub[3][3];
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
               char a = board[i][j];
                if(a != '.'){                     
                    if(row[i].count(a) || col[j].count(a) || sub[i/3][j/3].count(a))
                        return false;
                }
				col[j].insert(a);
				row[i].insert(a);
				sub[i / 3][j / 3].insert(a);
            }
        }
	 return true;
}
};