// Using Bit manupulation
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int size = 1 << nums.size();
        vector<vector<int>> answer(size);
        for(int i = 0; i < size; i++){
            for(int j = 0; j < nums.size(); j++){
                // checking if jth bit is set or not
                if(i & (1 << j)){
                    answer[i].push_back(nums[j]);
                }
            }
        }
        return answer;
    }
};