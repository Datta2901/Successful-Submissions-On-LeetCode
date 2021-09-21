class Solution {
public:
    int findMin(vector<int>& nums) {
     int size = nums.size();
        if(nums.size() == 0){
            return -1;
        }
        if(nums.size() == 1){
            return nums[0];
        }
        int low = 0, high = size - 1;
        while(low < high){
            int mid = low + (high - low) /2;
            if(mid > 0 && nums[mid] < nums[mid - 1]){
                return nums[mid];
            }if(nums[mid] >= nums[low] && nums[mid] > nums[high]){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return nums[low];   
    }
};