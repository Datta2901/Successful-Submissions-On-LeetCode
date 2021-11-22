class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int maxUpto = values[0];
        int answer = INT_MIN;
        for(int i = 1; i < values.size(); i++){
            int curr = values[i];
            answer = max(answer,maxUpto + (curr - i));
            maxUpto = max(maxUpto,curr + i);
        }
        return answer;
    }
};