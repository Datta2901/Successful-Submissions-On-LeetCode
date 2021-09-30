class Solution {
public:
    vector<vector<int> > answer;
    
    void BackTracking(vector<int>&per,vector<int>nums,int start,int sum){
        if(sum < 0){
            return;
        }else if(sum == 0){
            answer.push_back(per);
        }else{
           for(int i = start; i < nums.size(); i++){
                per.push_back(nums[i]);
                BackTracking(per,nums,i,sum - nums[i]);
                per.pop_back();
            } 
        }
    }
    
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<int>per;
        BackTracking(per,candidates,0,target);
        return answer;
    }
};