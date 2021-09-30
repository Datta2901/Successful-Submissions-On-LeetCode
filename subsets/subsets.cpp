// BackTracking
class Solution {
public:
    vector<vector<int> > answer;
    void BackTrack(int start,vector<int> &sub,vector<int>& nums){
        answer.push_back(sub);
        for(int i = start; i < nums.size(); i++){
            sub.push_back(nums[i]);
            BackTrack(i + 1,sub,nums);
            sub.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>sub;
        BackTrack(0,sub,nums);
        return answer;
    }
};