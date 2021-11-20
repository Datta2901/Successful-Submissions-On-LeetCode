class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int include = 0;
        int exclude = 0;
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        vector<int> dp(maxi + 1,0);
        
        for(int i = 0; i < n; i++){
            dp[nums[i]]++;
        }
        
        for(int i = 0; i <= maxi; i++){
            int tempInclude =  exclude + dp[i] * i;
            int tempExclude = max(include,exclude);
            include = tempInclude;
            exclude = tempExclude ;

        }
        return max(include,exclude);
    }
};