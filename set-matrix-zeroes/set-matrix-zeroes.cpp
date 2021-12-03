class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        map<int,bool> cells;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    cells[i + 1] = true;
                    cells[-1 * (j + 1)] = true;
                    cout << i + 1 << " " << -1 * (j + 1) << endl;
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(cells[i + 1] || cells[-1 * (j + 1)]){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};