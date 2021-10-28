class Solution {
public:
    int findMin(vector<int>& nums) {
        int minimum = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            minimum = min(minimum,nums[i]);
        }
        return minimum;
    }
};