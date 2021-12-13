class Solution {
private:
    int n;
    int getAnswer(vector<int>&nums,int index,vector<int>&dp){
        if(index >= n){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        int Steal = nums[index] + getAnswer(nums,index + 2,dp);
        int notSteal = getAnswer(nums,index + 1,dp);
        return dp[index] = max(Steal,notSteal);
    }
public:
    int rob(vector<int>& nums) {
        n = nums.size();
        vector<int>dp(n,-1);
        return getAnswer(nums,0,dp);
    }
};