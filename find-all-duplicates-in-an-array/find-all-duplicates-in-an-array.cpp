class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if(nums.size() == 0){
            return {};
        } 
        vector<int> answer;
        for(int i = 0; i < nums.size(); i++){
            if(nums[abs(nums[i]) - 1 ] > 0){
                nums[abs(nums[i])- 1] *= -1;
            }else{
                answer.push_back(abs(nums[i]));
            }
        }
        return answer;
    }
};