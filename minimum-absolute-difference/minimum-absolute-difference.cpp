class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>>answer;
        int minDiff = INT_MAX;
        int n = arr.size();
        for(int i = 0; i < n - 1; i++){
            if(minDiff > arr[i + 1] - arr[i]){
                minDiff = arr[i + 1] - arr[i];
            }
        }
        // cout << minDiff << endl;
        for(int i = 0; i < n - 1; i++){
            if(minDiff == arr[i + 1] - arr[i]){
                answer.push_back({arr[i],arr[i + 1]});
            }
        }
      
        return answer;
    }
};