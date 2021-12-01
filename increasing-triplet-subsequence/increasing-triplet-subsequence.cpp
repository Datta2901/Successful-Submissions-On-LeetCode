class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a = INT_MAX,b = INT_MAX;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(a >= nums[i]){
                a = nums[i];
            }else if(b >= nums[i]){
                b = nums[i];
            }else if(b < nums[i]){
                return true;
            }
        }
        return false;
    }
        
};