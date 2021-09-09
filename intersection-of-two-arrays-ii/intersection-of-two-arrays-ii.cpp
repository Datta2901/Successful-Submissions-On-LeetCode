class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>answer;
        unordered_map<int,int> fre;
        for(auto it : nums1){
            fre[it]++;
        }
        for(int i = 0; i < nums2.size(); i++){
            if(fre[nums2[i]]){
                answer.push_back(nums2[i]);
                fre[nums2[i]]--;
            }
        }
        return answer;
    }
};