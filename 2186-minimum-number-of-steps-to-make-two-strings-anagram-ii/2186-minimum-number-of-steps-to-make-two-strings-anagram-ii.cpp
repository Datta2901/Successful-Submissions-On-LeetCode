class Solution {
public:
    int minSteps(string s, string t) {
        vector<int>fre(26,0);
        
        for(auto ch : s){
            fre[ch - 'a']++;
        }
        for(auto ch : t){
            fre[ch - 'a']--;
        }
        int answer = 0;
        for(int i = 0; i < 26; i++){
            answer += abs(fre[i]);
        }
        return answer;
    }
};