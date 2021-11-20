class Solution{

private: 
    int kadanesAlgorithm(vector<int>nums){
        int n = nums.size(),sum = 0;
        int maxUpto = 0,answer = INT_MIN;
        for(int i = 0; i < n; i++){
            maxUpto += nums[i];
            if(answer < maxUpto){
                answer = maxUpto;
            }if(maxUpto < 0){
                maxUpto = 0;
            }
        } 
        return answer;
    }
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size(),sum = 0;
        int answer = kadanesAlgorithm(nums);
        bool control =false;
        for(int i = 0; i < n; i++){
            nums[i] *= -1;
            sum += nums[i];
        }
        int answer2 = (-1 * sum) - (-1 * kadanesAlgorithm(nums));
        if(max(answer,answer2) == 0){
            return -1 * *min_element(nums.begin(),nums.end());
        }
        return max(answer,answer2); 
    }
};