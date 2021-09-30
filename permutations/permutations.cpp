class Solution {
public:
    
    vector<vector<int> > answer;
    
    void BackTrack(vector<int> &per ,vector<int> &nums, int start){
        if(per.size() == nums.size()){
            answer.push_back(per);
            return ;
        }
        for(int i = 0; i < nums.size(); i++){
            if(find(per.begin(),per.end(),nums[i]) != per.end()){
                continue;
            }
            per.push_back(nums[i]);
            BackTrack(per,nums,i + 1);
            per.pop_back();
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>per;
        BackTrack(per,nums,0);
        return answer;
    }
};