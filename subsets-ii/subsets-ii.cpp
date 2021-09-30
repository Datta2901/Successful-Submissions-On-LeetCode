// Using Bit Masking
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        map<vector<int>,int> fre;
        int size = 1 << nums.size();
        vector<vector<int>> answer;
        for(int i = 0; i < size; i++){
            vector<int>a;
            for(int j = 0; j < nums.size(); j++){
                if(i & (1 << j)){
                    a.push_back(nums[j]);
                }
            }
            sort(a.begin(),a.end());        
            if(fre[a] == 0){
                answer.push_back(a);
                fre[a] = 1;
            }
        }
        return answer;       
    }
};