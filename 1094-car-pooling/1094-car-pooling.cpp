class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int maxi = INT_MIN;
        for(auto it : trips){
            maxi = max(maxi,it[2]);
        }
        int n = trips.size();
        vector<int>timeline(maxi + 1,0);
        for(int i = 0; i < n; i++){
            timeline[trips[i][1]] += trips[i][0];
            timeline[trips[i][2]] -= trips[i][0];
        }
        
        if(timeline[0] > capacity){
            return false;
        }
        
        for(int i = 1; i <= maxi; i++){
            timeline[i] += timeline[i - 1];
            if(timeline[i] > capacity){
                return false;
            }
        }
        return true;
    }
};