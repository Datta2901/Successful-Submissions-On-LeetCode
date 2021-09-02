class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n,false);
        int answer = 0,count;
        for(int i = 0; i < n; i++){
            count = 1;
            if(!visited[i]){
                visited[i] = true;
                int index = i,startIndex = i;
                while(nums[startIndex] != index){
                    startIndex = nums[startIndex];
                    count++;
                    visited[startIndex] = true;
                }
            }
            answer = max(count,answer);
        }
        return answer;
    }
};