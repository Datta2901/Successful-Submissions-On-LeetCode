// class Solution {
// private:
//     map<int,int>fre;
// public:
//     int getAnswer(vector<int>&nums,int index,vector<int>&dp){
//         if(index >= nums.size()){
//             return 0;
//         }
//         if(dp[index] != -1){
//             return dp[index];
//         }
//         int pick = nums[index] + getAnswer(nums,index + 2,dp);
//         int notPick = getAnswer(nums,index + 1,dp);
//         return dp[index] = max(pick,notPick);
//     }
    
//     int deleteAndEarn(vector<int>& nums) {
//         int maxi = INT_MIN;
//         for(auto it : nums){
//             fre[it]++;
//             maxi = max(maxi,it);
//         }
//         vector<int>dp(maxi + 1,-1);
        
//         return getAnswer(nums,0,dp);
//     }
// };

class Solution {
private:
    map<int,int>fre;
public:
    
    int deleteAndEarn(vector<int>& nums) {
        int maxi = INT_MIN;
        int n = nums.size();
        for(auto it : nums){
            fre[it]++;
            maxi = max(maxi,it);
        }
        // cout << maxi << endl;
        
        vector<int>dp(maxi + 1,0);
        
        dp[1] = fre[1];
        if(n == 1){
            return fre[nums[0]] * nums[0];
        }
        dp[2] = max(dp[1],fre[2] * 2);
        for(int i = 3; i <= maxi; i++){
            dp[i] = max(dp[i - 1],dp[i - 2] + fre[i] * (i));
        }
        
        return dp[maxi];
    }
};