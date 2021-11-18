class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<bool>answer(nums.size() + 1,false);
        vector<int>disappear;
        for(int i = 0; i < nums.size(); i++){
            answer[nums[i]] = true;
        }
        for(int i = 1; i < answer.size(); i++){
            if(answer[i] == false){
                disappear.push_back(i);
            }
        }
        return disappear;
    }
};