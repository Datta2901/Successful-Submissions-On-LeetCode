class Solution {
public:
    string GetString(string s){
        string answer;
        answer = s[s.size() - 1];
        s.erase(s.end() - 1);
        answer += s;
        return answer;
    }
    string orderlyQueue(string s, int k) {
        string mini = s,a = s;
        if(k == 1){
           for(int i = 0; i < s.size(); i++){
               a = GetString(a);
               //cout << a << endl;
               mini = min(mini,a);
               //cout << a << endl;
           } 
           return mini;
        }
        sort(s.begin(),s.end());
        return s;
    }
};
