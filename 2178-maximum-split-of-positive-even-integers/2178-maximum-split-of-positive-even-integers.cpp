class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> answer;
        if(finalSum % 2 != 0){
            return answer;
        }
        long long ans = finalSum;
        long long s = 2;
        while(ans > 0){
            if(ans > s){
                answer.push_back(s);
            }else{
                int diff = s - ans;
                answer.push_back(s);
                // cout << s << " " << ans << endl;
                if(diff >= 2){
                    auto it =  find(answer.begin(),answer.end(),diff);
                    answer.erase(it);
                }
                break;
            }
            ans -= s;
            s += 2;
        } 
        return answer;
    }
};