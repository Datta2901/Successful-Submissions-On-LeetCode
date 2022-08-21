class Solution {
public:
    bool isValid(string s) {
        stack<char> bal;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '{'|| s[i] == '['){
                bal.push(s[i]);
            }else{
                if(bal.empty()){
                    return false;
                }
                if(s[i] == ')' && bal.top() == '('){
                    bal.pop();
                }else if(s[i] == '}' && bal.top() == '{'){
                    bal.pop();
                }else if(s[i] == ']' && bal.top() == '['){
                    bal.pop();
                }else{
                    return false;
                }
           }
        }
        if(!bal.empty()){
            return false;
        }
        return true;
    }
};