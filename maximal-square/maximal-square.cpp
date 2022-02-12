// class Solution {
// public:
//     int maximalSquare(vector<vector<char>>& matrix) {
//         if (matrix.empty()) {
//             return 0;
//         }
//         int m = matrix.size(), n = matrix[0].size(), sz = 0;
//         vector<vector<int>> dp(m, vector<int>(n, 0));
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (!i || !j || matrix[i][j] == '0') {
//                     dp[i][j] = matrix[i][j] - '0';
//                 } else {
//                     dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
//                 }
//                 sz = max(dp[i][j], sz);
//             }
//         }
//         return sz * sz;
//     }
// };

// Recursive
class Solution {
    int maxi;
    int m,n;
    
    bool isValid(int i,int j){
        if(i < 0 || i >= m || j >= n || j < 0){
            return false;
        }
        return true;
    }
    
    int dfs(int i,int j,vector<vector<char>>& matrix, vector<vector<int> >&dp){
        if(!isValid(i,j)){
            return 0;
        }
        if(matrix[i][j] == '0'){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int one = dfs(i,j + 1,matrix,dp);
        int two = dfs(i + 1,j + 1,matrix,dp);
        int three = dfs(i + 1,j,matrix,dp);
        return dp[i][j] = 1 + min({one,two,three});
    }
    
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        maxi = 0;
        vector<vector<int> > dp(m,vector<int> (n,-1));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '1'){
                    maxi = max(maxi,dfs(i,j,matrix,dp));
                }
            }
        }
        return maxi * maxi;
    }
};