class Solution {
    string getString(int in1,int in2,string s){
        string ans = "";
        for(int i = in1; i < in2; i++){
            ans += s[i];
        }
        return ans;
    }
public:
    int minimumLengthEncoding(vector<string>& words) {
        int n = words.size();
        set<string>answer;
        for(auto it : words){
            answer.insert(it);
        }
        for(int i = 0; i < n; i++){
            for(int j = 1; j < words[i].size(); j++){
                string sub = getString(j,words[i].size(),words[i]);
                answer.erase(sub);
            }
        }
        int length = 0;
        for(auto it : answer){
            length += it.size() + 1;
        }
        return length;
    }
};