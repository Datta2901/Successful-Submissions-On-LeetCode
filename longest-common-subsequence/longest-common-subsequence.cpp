class Solution {
public:
    int LCS(string a,string b){
        int m = a.size(),n = b.size();
        int dp[m + 1][n + 1];
        for(int i = 0; i <= m; i++){
            dp[i][0] = 0;
        }
        for(int j = 0; j <= n; j++){
            dp[0][j] = 0;
        }

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(a[i - 1] == b[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }else{
                    dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int m  = text1.size(),n = text2.size();
        return LCS(text1,text2);
    }
};

// class Solution{
//     int m,n;
//     int getAnswer(string a,string b,int i,int j,vector<vector<int> > &dp){
//         if(i == m || j == n){
//             return 0;
//         }
//         if(dp[i][j] != -1){
//             return dp[i][j];
//         }
//         if(a[i] == b[j]){
//             return dp[i][j] =  1 + getAnswer(a,b,i + 1,j + 1,dp);
//         }
//         return dp[i][j] = max(getAnswer(a,b,i + 1,j,dp),getAnswer(a,b,i,j + 1,dp));
//     }
//   public:
//     int longestCommonSubsequence(string a,string b){
//         m = a.size();
//         n = b.size();
//         vector<vector<int> > dp(m + 1,vector<int>(n + 1,-1));
//         return getAnswer(a,b,0,0,dp);
//     }
// };
