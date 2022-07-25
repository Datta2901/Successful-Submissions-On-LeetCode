// // Memoization
// class Solution {
// private:
//     int n;
//     int getAnswer(vector<int>&nums,int index,vector<int>&dp){
//         if(index >= n){
//             return 0;
//         }
//         if(dp[index] != -1){
//             return dp[index];
//         }
//         int Steal = nums[index] + getAnswer(nums,index + 2,dp);
//         int notSteal = getAnswer(nums,index + 1,dp);
//         return dp[index] = max(Steal,notSteal);
//     }
// public:
//     int rob(vector<int>& nums) {
//         n = nums.size();
//         vector<int>dp(n,-1);
//         return getAnswer(nums,0,dp);
//     }
// };

class Solution {
    int getAnswer(vector<int>&nums,int i){
        if(i >= nums.size()){
            return 0;
        }
        int pick = nums[i] + getAnswer(nums, i + 2);
        int notPick = getAnswer(nums,i + 1);

        return max(pick,notPick);
    }
    int getAnswer(vector<int>&nums,int i,vector<int>&dp){
        if(i >= nums.size()){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int pick = nums[i] + getAnswer(nums, i + 2,dp);
        int notPick = getAnswer(nums,i + 1,dp);
        return dp[i] = max(pick,notPick);
    }
    int getAnswer(vector<int>nums){
        vector<int>dp(nums.size(),0);
        int n = nums.size();
        dp[0] = nums[0];
        if(nums.size() > 1)
        dp[1] = max(nums[1],nums[0]); 
        for(int i = 2; i < n; i++){
            int one = nums[i] + dp[i - 2];
            int two = dp[i - 1];
            dp[i] = max(one,two);
        }
        return dp[n - 1];
    }
public:
    int rob(vector<int>& nums) {
        return getAnswer(nums);
    }
};