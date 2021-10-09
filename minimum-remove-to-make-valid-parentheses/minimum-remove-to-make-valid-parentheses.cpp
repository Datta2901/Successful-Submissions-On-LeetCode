class Solution {
public:

    string minRemoveToMakeValid(string s) {
        string answer = "";
        int open = 0;
        int closed = 0;
        map<int,int>index;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
               open++;
            }else if(s[i] == ')'){
                open--;
                if(open < 0){
                    index[i] = 1;
                    open += 1;
                }
            }
        }

        // cout << open << endl;
        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i] == '(' && open >= 1){
                index[i] = 1;
                open--;
            }
        }
        // cout << open << endl;


        for(int i = 0; i < s.size(); i++){
            if(index[i] == 1){
                s[i] = '@';
            }
        }

        for(int i = 0; i < s.size(); i++){
            if(s[i] != '@'){
                answer += s[i];
            }
        }

        return answer;
    }
};



// Space and time Optmization
class Solution {
public:

    string minRemoveToMakeValid(string s) {
        string answer = "";
        int open = 0;
        int closed = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
               open++;
            }else if(s[i] == ')'){
                open--;
                if(open < 0){
                    s[i] = '@';
                    open += 1;
                }
            }
        }

        // cout << open << endl;
        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i] == '(' && open >= 1){
                s[i] = '@';
                open--;
            }
        }
        // cout << open << endl;

        for(int i = 0; i < s.size(); i++){
            if(s[i] != '@'){
                answer += s[i];
            }
        }

        return answer;
    }
};


// More Space Optmization

class Solution {
public:

    string minRemoveToMakeValid(string s) {
        // string answer = "";
        int open = 0;
        int closed = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
               open++;
            }else if(s[i] == ')'){
                open--;
                if(open < 0){
                    s[i] = '@';
                    open += 1;
                }
            }
        }

        // cout << open << endl;
        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i] == '(' && open >= 1){
                s[i] = '@';
                open--;
            }
        }
        // cout << open << endl;

        s.erase(remove(s.begin(),s.end(),'@'),s.end());

        return s;
    }
};



