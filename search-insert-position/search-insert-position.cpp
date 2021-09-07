class Solution {
public:
    int binarySearch(vector<int>& nums,int target){
        int low = 0,high = nums.size() - 1,answer= -1;
        while(low <= high){
            int mid = (low + high) /2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] > target){
                answer= mid;
                high = mid - 1;
            }else{
                answer = mid + 1;
                low = mid + 1;
            }
        }
        return answer;
    }
    int searchInsert(vector<int>& nums, int target) {
        int answer = binarySearch(nums,target);
        return answer; 
    }
};