class Solution {
private:
    vector<vector<int> >answer;
    void printSubsets(vector<int>&nums){
        for(auto &it : nums){
            cout << it << " ";
        }
        cout << endl;
    }

    void getSubsets(int ind,vector<int>&sub,vector<int>&nums){
        if(ind >= nums.size()){
            printSubsets(sub);
            answer.push_back(sub);
            return;
        }
        //pick this current element to our subset
        sub.push_back(nums[ind]); 
        getSubsets(ind + 1,sub,nums);
        sub.pop_back();

        // not pick the current element to our subet
        getSubsets(ind + 1,sub,nums);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> sub;
        getSubsets(0,sub,nums);
        return answer;
    }
};