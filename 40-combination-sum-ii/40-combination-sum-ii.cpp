class Solution {
public:
    vector<vector<int> > answer;
    
    void combinationSum(vector<int>&nums,vector<int>&ds,int i, int k){
        if(k == 0){
            answer.push_back(ds);
        }

        for(int next = i; next < nums.size(); next++){
            if(next > i && nums[next] == nums[next - 1]){
                continue;
            }
            if(nums[next] <= k){
                ds.push_back(nums[next]);
                combinationSum(nums,ds,next + 1,k - nums[next]);
                ds.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>ds;
        combinationSum(candidates,ds,0,target);
        return answer;
    }
};

// class Solution {
//     vector<vector<int> > answer;
//     set<vector<int> > order;
//     void CombinationSum2(vector<int>&nums,vector<int>&ds,int i,int k){
//         if(i == nums.size()){
//             if(k == 0){
//                 order.insert(ds);
//             }
//             return ;
//         }

//         if(nums[i] <= k){
//             ds.push_back(nums[i]);
//             CombinationSum2(nums,ds,i + 1,k - nums[i]);
//             ds.pop_back();
//         }
//         CombinationSum2(nums,ds,i + 1,k);
//     }
// public:
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         vector<int>ds;
//         sort(candidates.begin(),candidates.end());
//         CombinationSum2(candidates,ds,0,target);
//         for(auto it : order){
//             answer.push_back(it);
//         }
//         return answer;
//     }
// };

