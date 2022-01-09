class Solution {
    vector<vector<int> > dp;
    int EditDistanceMemo(string &A,string &B,int i, int j){
        if(i == 0){
            return j;
        }
        if(j == 0){
            return i;
        }
        if(dp[i - 1][j - 1] != -1){
            return dp[i - 1][j - 1];
        }
        if(A[i - 1] == B[j - 1]){
            return dp[i - 1][j - 1] = EditDistanceMemo(A,B,i - 1,j - 1);
        }
        int answer = 1 +  min({EditDistanceMemo(A,B,i - 1,j),EditDistanceMemo(A,B,i,j - 1),EditDistanceMemo(A,B,i - 1,j - 1)});
        return dp[i - 1][j - 1] = answer;
    }
  
public:
    int minDistance(string word1, string word2) {
        vector<vector<int> > dp1(word1.size(),vector<int>(word2.size(),-1));
        dp = dp1;
        return EditDistanceMemo(word1,word2,word1.size(),word2.size());
    }
};