class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int>track;
        track.push(start);
        while(!track.empty()){
            int pos = track.front();
            track.pop();
            if(arr[pos] == 0){
                return true;
            }
            if(arr[pos] < 0){
                continue;
            } 
            if(pos + arr[pos] < n){
                track.push(pos + arr[pos]);
            }
            if(pos - arr[pos] >= 0){
                track.push(pos - arr[pos]);
            }
            arr[pos] *= -1;
        }
        return false;
    }
};