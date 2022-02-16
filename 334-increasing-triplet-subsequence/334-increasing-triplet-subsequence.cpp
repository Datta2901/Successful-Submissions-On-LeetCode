class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX,second = INT_MAX;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(first >= nums[i]){
                first = nums[i];
            }else if(second >= nums[i]){
                second = nums[i];
            }else if(second < nums[i]){
                return true;
            }
        }
        return false;
    }
};