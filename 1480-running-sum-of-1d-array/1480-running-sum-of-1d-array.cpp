class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum = 0;
        int size = nums.size();
        vector<int>answer(size,0);
        for(int i = 0; i < size; i++){
            sum += nums[i];
            answer[i] = sum;
        }
        return answer;
    }
};