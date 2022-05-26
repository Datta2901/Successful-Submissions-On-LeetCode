// class Solution {
// public:
//     int nthUglyNumber(int n) {
//         if(n <= 0) return false; 
//         if(n == 1) return true; 
//         int t2 = 0, t3 = 0, t5 = 0; 
//         vector<int> dp(n);
//         dp[0] = 1;
//         for(int i  = 1; i < n ; i ++){
//             dp[i] = min({dp[t2]*2,dp[t3]*3,dp[t5]*5});
//             if(dp[i] == dp[t2]*2){
//                 t2++;
//             }    
//             if(dp[i] == dp[t3]*3){
//                 t3++;
//             } 
//             if(dp[i] == dp[t5]*5){
//                 t5++;
//             } 
//         }
//         return dp[n-1];
//     }
// };

class Solution {
public:
    int nthUglyNumber(int n) {
        if(n <= 0) return false; 
        if(n == 1) return true; 
        priority_queue<long,vector<long>,greater<long>>pq;
        pq.push(1l);
        for(int i = 0; i < n - 1; i++){
            long val = pq.top();
            // cout << val << " ";
            pq.pop();
            while(!pq.empty() && pq.top() == val){
                pq.pop();
            }
            pq.push(val * 2);
            pq.push(val * 3);
            pq.push(val * 5);
        }
        if(pq.empty()){
            return 1;
        }
        return pq.top();
    }
};