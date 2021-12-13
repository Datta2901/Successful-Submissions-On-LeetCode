class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int n = nums.size();
        int maxi = nums[0];
        int prefix = 1;
        int suffix = 1;
        for(int i = 0; i < n; i++){
            if(prefix == 0){
                prefix = 1;
            }if(suffix == 0){
                suffix = 1;
            }
            prefix *= nums[i];
            suffix *= nums[n - i - 1];
            maxi = max({prefix,suffix,maxi});
        }
        return maxi;
    }
};
