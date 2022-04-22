class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int m = arr1.size();
        int n = arr2.size();
        int answer = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(abs(arr1[i] - arr2[j]) <= d){
                    break;
                }
                if(j == n - 1){
                    answer++;
                }
            }
        }
        return answer;
    }
};