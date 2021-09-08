class Solution {
public:
    
    int search(vector<int>& nums, int target) {
        int low = 0,high = nums.size() - 1;
        while(low <= high){
            int mid = (high + low)/2;
            if(nums[mid]== target){
                return mid;
            }else if(nums[mid] > target){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return -1;
    }
    
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>answer;
        for(int i = 0; i < numbers.size(); i++){
            int diff;
            if(target < numbers[i]){
                diff = numbers[i] - target; 
            }else{
                diff = target - numbers[i];
            }
            int a = search(numbers,diff);
            
            if(a != -1){
                if(i != a){
                    answer.push_back(min(i + 1,a + 1));
                    answer.push_back(max(i + 1,a + 1));
                    return answer;
                }
            }
        }
        return answer;
    }
};