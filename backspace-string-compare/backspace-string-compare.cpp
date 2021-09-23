class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> a,b;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '#'){
                if(!a.empty())
                    a.pop();
            }else{
                a.push(s[i]);
            }
        }
        for(int i = 0; i < t.size(); i++){
            if(t[i] == '#'){
                if(!b.empty())
                    b.pop();
            }else{
                b.push(t[i]);
            }
        }
        return a == b;
    }
};