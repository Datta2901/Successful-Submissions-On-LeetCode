// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         int Max = amount + 1;
//         vector<int> dp(amount + 1, Max);
//         dp[0] = 0;
//         for (int i = 1; i <= amount; i++) {
//             for (int j = 0; j < coins.size(); j++) {
//                 if (coins[j] <= i) {
//                     dp[i] = min(dp[i], dp[i - coins[j]] + 1);
//                 }
//             }
//         }
//         return dp[amount] > amount ? -1 : dp[amount];
//     }
// };



class Solution {
    int getAnswer(int i,vector<int>&coins,int amount,vector<vector<int> > &dp){
        if(i == coins.size()){
            return INT_MAX - 1;
        }
        if(amount == 0){
            return 0;
        }
        if(dp[i][amount] != -1){
            return dp[i][amount];
        }
        
        int pick = INT_MAX,notPick = INT_MAX;
        if(coins[i] <= amount){
            pick = 1 + getAnswer(i,coins,amount-coins[i],dp);
        }
        notPick = getAnswer(i + 1,coins,amount,dp);
        return dp[i][amount] = min(pick,notPick); 
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int> > dp(coins.size(),vector<int>(amount + 1,-1));
        int answer = getAnswer(0,coins,amount,dp);
        if(answer == INT_MAX || answer == INT_MAX -1){
            return -1;
        }
        return answer;
    }
};


