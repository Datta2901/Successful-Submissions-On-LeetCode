class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;   
        int start = 0;
        int end = nums.size() - 1;
        
        while(start < end) {
            int sum = nums[start] + nums[end];
            if(sum > target) {
                end--;
            }else if(sum < target) {
                start++;
            }else{
                return vector<int>{start + 1, end + 1};
            }
        }
        
        return vector<int>{start + 1, end + 1};
    }
};