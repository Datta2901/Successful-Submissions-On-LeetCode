class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int>fre;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            fre[nums[i]]++;
            if(fre[nums[i]] > 1){
                return true;
            }
        }
        return false;
    }
};