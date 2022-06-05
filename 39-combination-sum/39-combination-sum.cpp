// class Solution {
// public:
//     vector<vector<int> > answer;
//     void GetAnswer(vector<int>&ds,vector<int>&nums,int ind,int sum,int target){
//         if(sum > target){
//             return;
//         }
//         if(ind >= nums.size()){
//             return;
//         }
//         if(sum == target){
//             answer.push_back(ds);
//             return;
//         }

//         // pick
//         if(target >= nums[ind]){
//             ds.push_back(nums[ind]);
//             sum += nums[ind];
//             GetAnswer(ds,nums,ind,sum,target);
//             sum -= nums[ind];
//             ds.pop_back();
//         }

//         // not pick
//         GetAnswer(ds,nums,ind + 1,sum,target);
//     }
    
//     vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
//         vector<int>ds;
//         GetAnswer(ds,candidates,0,0,target);
//         return answer;
//     }
// };


class Solution {
public:
    vector<vector<int> > answer;
    
    void AllsubsequencesHavingSumk(vector<int>&nums,vector<int>&ds,int i,int sum,int k){
        if(i == nums.size()){
            if(k == 0){
                answer.push_back(ds);
            }
            return;
        }

        // Pick
        if(nums[i] <= k){
            ds.push_back(nums[i]);
            AllsubsequencesHavingSumk(nums,ds,i,sum,k - nums[i]);
            ds.pop_back();
        }

        // notpick
        AllsubsequencesHavingSumk(nums,ds,i + 1,sum,k);
    }
     
    vector<vector<int> > combinationSum(vector<int>& nums,int k){
        vector<int>ds;
        AllsubsequencesHavingSumk(nums,ds,0,0,k);
        return answer;
    }
};

