class Solution {
    unordered_map<string,int> fre;
    bool getAnswer(int i,string s,vector<string>&wordDict,vector<int>&dp){
        if(i == s.size()){
            return true;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        for(int j = i + 1;j <= s.size(); j++){
            string sub = s.substr(i,j - i);
            if(fre[sub] == 1){
                if(getAnswer(j,s,wordDict,dp)){
                    return dp[i] = true;
                }
            }
        }
        return dp[i] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto i : wordDict){
            fre[i]++;
        }
        int n = s.size();
        vector<int>dp(n,-1);
       return getAnswer(0,s,wordDict,dp);
    }
};