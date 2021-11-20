class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1){
            return 0;
        }
        int n = nums.size();
        vector<int>dp(n, 0);
        dp[n - 1] = 0;
        for(int i  = n - 2; i >= 0; i--){
            int mini = *min_element(dp.begin() + i + 1,dp.begin() + min(i + nums[i],n - 1) + 1);
            dp[i] = 1 + mini;
        }
        return dp[0];
    }
};