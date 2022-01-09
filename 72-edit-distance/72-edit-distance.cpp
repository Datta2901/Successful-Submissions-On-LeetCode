// Tabulation
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

// Recursive
class Solution {
    int mini(int a,int b,int c){
        return min(a,min(b,c));
    }

int EditDistanceRecursive(string &A,string &B,int i,int j){
    if(i == 0){
        return j;
    }
    if(j == 0){
        return i;
    }
    if(A[i - 1] == B[j - 1]){
            //before answer   //just call next ones
        return EditDistanceRecursive(A,B,i - 1, j - 1);
    }
                     //Insert                             //Delete                       //Replace
    // int answer = 1 + min({EditDistanceRecursive(A,B,i,j - 1),EditDistanceRecursive(A,B,i - 1,j),EditDistanceRecursive(A,B,i - 1,j - 1)});
    int answer = 1 + mini(EditDistanceRecursive(A,B,i,j - 1),EditDistanceRecursive(A,B,i - 1,j),EditDistanceRecursive(A,B,i - 1,j - 1));
    return answer;
}
  
public:
    int minDistance(string word1, string word2) {
        return EditDistanceRecursive(word1,word2,word1.size(),word2.size());
    }
};

// Memoization
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
