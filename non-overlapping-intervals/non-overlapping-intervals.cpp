class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int m = intervals.size();
        int current = 0,next = 1,answer = 0;
        while(next < m){
            //not overlapping
            if(intervals[current][1] <= intervals[next][0]){
                current = next;
                next++;
            }//overlapping and remove the right interval
            else if(intervals[current][1] <= intervals[next][1]){
                answer += 1;
                next++;
            }else if(intervals[current][1] > intervals[next][1]){
                answer += 1;
                current = next;
                next++;
            }
        }
        return answer;
    }
};