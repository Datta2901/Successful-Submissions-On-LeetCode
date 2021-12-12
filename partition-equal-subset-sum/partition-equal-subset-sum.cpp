class Solution {
private:
    vector<vector<int>> dp;
    bool SubsetSumProblem(vector<int>&nums,int target,int sum,int index){
        if(index >= nums.size()){
            return false;
        }
        if(sum > target){
            return false;
        }
        if(sum == target){
            return true;
        }
        if(dp[index][sum] != -1){
            return dp[index][sum];
        }
        return dp[index][sum] = SubsetSumProblem(nums,target,sum + nums[index],index + 1) || SubsetSumProblem(nums,target,sum,index + 1);
    }


public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        if(sum % 2 == 1){
            return false;
        }
        sum /= 2;
        dp.clear();
        dp.resize(n + 1,vector<int>(sum + 1,-1));
        return SubsetSumProblem(nums,sum,0,0);        
    }
};