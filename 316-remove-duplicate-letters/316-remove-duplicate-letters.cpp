class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        vector<int>fre(26,0);
        vector<bool>visited(26,0);
        string answer = "";
        for(int i = 0; i < n; i++){
            fre[s[i] - 'a'] = i;
        }
        
        for(int i = 0; i < n; i++){
            if(visited[s[i] - 'a']){
                continue;
            }
            while(answer.size() > 0 && answer[answer.size() - 1] > s[i] && fre[answer[answer.size() - 1] - 'a'] > i){
                visited[answer[answer.size() - 1] - 'a'] = false;
                answer.pop_back();
            }
            answer += s[i];
            visited[s[i] - 'a'] = true;
        }
        return answer;
    }
};