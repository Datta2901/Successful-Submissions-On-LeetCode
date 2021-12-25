class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int size = nums.size();
        int answer = INT_MIN;
        int count = 0;
        for(int i = 0; i < size; i++){
            if(nums[i] == 1){
                count++;
            }else{
                count = 0;
            }
            answer = max(answer,count);
        }
        return answer;
    }
};