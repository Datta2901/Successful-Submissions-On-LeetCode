// Linear Search Solution
// class Solution {
// public:
//     long long minimumTime(vector<int>& time, int totalTrips) {
//         int n = time.size();
//         for(int t = 1; ; t++){
//             long long  count = 0;
//             for(int i = 0; i < n; i++){
//                 count += t / time[i] ;
//             }
//             if(count >= totalTrips){
//                 return t;
//             }
//         }
//         return 0;
//     }
// };

// Binary Search Solution
class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        long long  low = 0,high = 1e14;
        long long answer = 0;
        while(low <= high){
          long long mid = (high + low) / 2;
          long long  count = 0;
            for(int i = 0; i < n; i++){
                count += (mid / time[i]) ;
            }
            if(count < totalTrips){
                low = mid + 1;
            }else{
                answer = mid;
                high = mid - 1;
            }
        }
        return answer;
    }
};