class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //min Priority Queue         
        priority_queue<int,vector<int>,greater<int>> pq;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            pq.push(nums[i]);
            if(pq.size() > k){
                pq.pop();
            }
        }
        // int ans = pq.top();
        // while(!pq.empty()){
        //     cout << pq.top() << " ";
        //     pq.pop();
        // }
        // return ans;
        return pq.top();
    }
};