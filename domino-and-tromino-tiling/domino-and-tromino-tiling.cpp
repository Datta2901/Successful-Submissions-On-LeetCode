class Solution {
public:
    #define ll long long
    #define MOD 1000000007
    int numTilings(int n) {
        vector<ll> dp(n+1);
        for(int i = 0; i <= n; i++){
            dp[i] = i;
        }
        // for(auto it : dp){
        //     cout << it << " ";
        // }
        dp[0] = 1;
        for(int i=3;i<=n;i++)
            dp[i] = (dp[i-1]+dp[i-1]+dp[i-3])%MOD;
        return dp.back();
    }
};