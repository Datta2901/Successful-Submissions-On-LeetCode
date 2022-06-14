class Solution {
public:
    int lcs(string s1,string s2,int i,int j,vector<vector<int>>&dp){
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(i == 0 || j == 0){
            return dp[i][j] = 0;
        }
        
        if(s1[i - 1] == s2[j - 1]){
            return dp[i][j] = 1 + lcs(s1,s2,i - 1, j - 1,dp);
        }
        return dp[i][j] = max(lcs(s1,s2,i - 1,j,dp),lcs(s1,s2,i, j - 1,dp));
    }
    
    int minDistance(string word1, string word2){
        int n = word1.size();  
        int m = word2.size(); 
        vector<vector<int> > dp(n + 1,vector<int>(m + 1,-1));
        int ans = lcs(word1,word2,n,m,dp);
        // cout << ans << endl;
        return (n+m) - (2*ans);
    }
};