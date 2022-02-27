
// class Solution {
// public:
    
//     int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
//         int count=0;
//         unordered_map<int,int> mp;    
//         for (auto &it1: nums1)
//             for (auto &it2:nums2)
//                 mp[it1+it2]++; 
     
//         for(auto &it3: nums3)
//             for(auto &it4:nums4)
//                if(mp.count(0-it3-it4)) count+=mp[0-it3-it4];
        
//         return count;
//     }
// };























class Solution {
public:
    
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int answer = 0;
        map<int,int>mp;
        for(auto it : nums1){
            for(auto i : nums2){
                mp[it + i]++;
            }
        }
        
        for(auto it : nums3){
            for(auto i : nums4){
                answer += mp[0 - it - i];
            }
        }
        return answer;
    }
};
