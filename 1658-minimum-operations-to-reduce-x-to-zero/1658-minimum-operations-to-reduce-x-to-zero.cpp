class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int size = nums.size();
        int left = 0,right = 0;
        int answer = INT_MAX;
        while(left <= right){
            if(sum >= x){
                if(sum == x){
                    answer = min(answer, size - right + left);
                } 
                if(right < size){
                    sum -= nums[right];
                    right++;
                }else{
                    break;
                }
            }else{
                sum += nums[left];
                left++;
            }
        }
        if(answer == INT_MAX){
            return -1;
        }
        return answer;
    }
};