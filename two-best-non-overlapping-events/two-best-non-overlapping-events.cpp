// Dp
class Solution {
private:
    int GetAnswer(int index,int jobs,vector<vector<int> >& events,vector<vector<int> >& dp){
        if(index == events.size() || jobs == 2){
            return 0;
        }
        if(dp[index][jobs] != -1){
            return dp[index][jobs];
        }
        vector<int> a = {events[index][1],INT_MAX,INT_MAX};
        int nextIndex = upper_bound(events.begin(),events.end(),a)-events.begin();
        int answer1 =  events[index][2] + GetAnswer(nextIndex,jobs + 1,events,dp); 
        int answer2 = GetAnswer(index + 1,jobs,events,dp);
        return dp[index][jobs] = max(answer1,answer2);
    }
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<vector<int> > dp(events.size(),vector<int>(2,-1));
        sort(events.begin(),events.end());
        return GetAnswer(0,0,events,dp);
    }
};