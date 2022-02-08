class Solution {
    vector<string> store = {"","","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"},answer;
    void getAnswer(int i,string &digits,string &comb){
        if(comb.size() == digits.size()){
            answer.push_back(comb);
            return;
        }
        for(auto ch : store[digits[i] - '0']){
            comb.push_back(ch);
            getAnswer(i + 1,digits,comb);
            comb.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0){
            return {};
        }
        string comb = "";
        getAnswer(0,digits,comb);
        return answer;
    }
};