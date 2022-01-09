class Solution {
    int EditDistanceTab(string A,string B){
        int m = A.size();
        int n = B.size();
        vector<vector<int> > dp(m + 1,vector<int>(n + 1,0));
        for(int i = 0; i <= m; i++){
            dp[i][0] = i;
        }
        for(int j = 0; j <= n; j++){
            dp[0][j] = j;
        }
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(A[i - 1] == B[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1];
                }else{
                    dp[i][j] = 1 + min({dp[i - 1][j],dp[i][j - 1],dp[i - 1][j - 1]});
                }
            }
        }
        return dp[m][n];
    }
  
public:
    int minDistance(string word1, string word2) {
        return EditDistanceTab(word1,word2);
    }
};