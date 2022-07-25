class Solution {
    int HouseRobberI(vector<int>nums){
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
        int size = nums.size();
        if (size == 0) return 0;
        if (size == 1) return nums[0];
        if(size == 2) return max(nums[0],nums[1]);
        vector<int>a1,a2;
        for(int i = 0; i < size; i++){
            if(i != 0){
                a1.push_back(nums[i]);
            }
            if(i != size - 1){
                a2.push_back(nums[i]);
            }
        }
        return max(HouseRobberI(a1),HouseRobberI(a2));
    }
};