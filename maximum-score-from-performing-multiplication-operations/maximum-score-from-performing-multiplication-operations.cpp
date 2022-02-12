class Solution {
    int dp[1000][1000];
    int getAnswer(vector<int>&nums,vector<int>&multipliers,int i,int l,int r){
        if(i >= multipliers.size()){
            return 0;
        }
        if(dp[l][i] != -1){
            return dp[l][i];
        }
        int leftProduct = nums[l] * multipliers[i] + getAnswer(nums,multipliers,i + 1,l + 1,r);
        int rightProduct = nums[r] * multipliers[i] + getAnswer(nums,multipliers,i + 1,l, r - 1);
        return dp[l][i] = max(leftProduct,rightProduct);
    }
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();
        // vector<vector<int> > dp(n,vector<int>(m,-1));
        memset(dp,-1,sizeof(dp));
        return getAnswer(nums,multipliers,0,0,nums.size() - 1);
    }
};