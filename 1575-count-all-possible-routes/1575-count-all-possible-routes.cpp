class Solution{
private:
    int mod = int(1e9) + 7;
    int getAnswer(vector<int>&locations,int finish,int fuel,int index,vector<vector<int> > &dp){
        if(index >= locations.size()){
            return 0;
        }
        if(fuel < 0){
            return 0;
        }
        if(dp[index][fuel] != -1){
            return dp[index][fuel];
        }
        int answer = 0;
        if(finish == index){
            answer++;
        }
        // cout << answer << endl;
        for(int i = 0; i < locations.size(); i++){
            if(i != index){
                answer += getAnswer(locations,finish,fuel - abs(locations[i] - locations[index]),i,dp);
                answer = answer % mod;
            }
        }
        return dp[index][fuel] = answer;
    }
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        int maxi = 201;
        vector<vector<int> >dp(n,vector<int>(maxi + 1,-1));
       return getAnswer(locations,finish,fuel,start,dp);
    }
};