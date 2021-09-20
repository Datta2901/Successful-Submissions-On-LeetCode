class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>fre;
        for(auto it : nums){
            fre[it]++;
        }
        for(auto it : fre){
            if(it.second > nums.size()/2){
                return it.first;
            }
        }
        return 0;
    }
};