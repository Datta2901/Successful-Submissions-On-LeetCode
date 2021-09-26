class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>fre;
        vector<int>answer;
        for(int i = 0; i < s.size(); i++){
            fre[s[i]]++;
        }
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            bool add = true;
            if(fre[s[i]] - 1 == 0){
                ans += s[i];
                fre[s[i]]--;
                for(int i = 0; i < ans.size(); i++){
                    if(fre[ans[i]] != 0){
                        add = false;
                        break;
                    }
                }
                if(add){
                    answer.push_back(ans.size());
                    ans = "";
                }
            }else{
                ans += s[i];
                fre[s[i]]--;
            }
        }
        if(ans.size() > 0){
            answer.push_back(ans.size());
        }
        return answer;
    }
};