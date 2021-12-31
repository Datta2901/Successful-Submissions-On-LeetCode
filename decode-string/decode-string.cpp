class Solution {
private:
    string getMultipliedString(string s,int a){
        string ans = "";
        for(int i = 0; i < a; i++){
            ans += s;
        }
        return ans;
    }
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> wordStack;
    
        int number = 0;
        string word = "";
        for (int i = 0; i < s.length(); ++i) {
            char ch = s[i];
            if (isdigit(ch)) {
                number = number * 10 + (ch - '0');
                //number += (s[i] - '0');
            }
            else if (isalpha(ch)) {
                word += ch;
            } 
            else if (s[i] == '[') {
                wordStack.push(word);
                countStack.push(number);
                word = "";
                number = 0;
            } 
            else {
                int topMult = countStack.top();
                countStack.pop();
                string topS = wordStack.top(); 
                wordStack.pop();
                topS += getMultipliedString(word,topMult);
                word = topS; 
            } 
        }
        
        return word;
    }
};
