bool cmp(vector<int>&a,vector<int>&b){
    return a[1] < b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Sort by endTime     
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),cmp);
        int endTime = intervals[0][1];
        int answer = 0;
        for(int i = 1; i < n; i++){
            if(endTime > intervals[i][0]){
                answer++;
            }else{
                endTime = intervals[i][1];
            }
        }
        return answer;
    }
};