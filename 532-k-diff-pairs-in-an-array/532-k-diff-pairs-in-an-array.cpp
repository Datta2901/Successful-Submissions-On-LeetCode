class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }
        int count=0;
        for(auto i:mp){
            if(k == 0){
                if(i.second > 1){
                    count++;
                }
            }else{        
                if(mp.find(i.first+k)!=mp.end()){
                    count++;
                } 
            }
        }
        return count;
    }
};