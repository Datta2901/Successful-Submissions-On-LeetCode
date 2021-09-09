class Solution {
public:
    string reverseWords(string s) {
        string answer,word = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                reverse(word.begin(),word.end());
                answer += word;
                answer += ' ';
                word = "";
            }else{
                word += s[i];
            }
        }
        reverse(word.begin(),word.end());
        answer += word;
        return answer;
    }
};