class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0; i < n; i++){
            if(arr[abs(arr[i])] > 0){
                arr[abs(arr[i])] = -1 * arr[abs(arr[i])]; 
            }else{
                return abs(arr[i]);
            }
        }
        return -1;
    }
};