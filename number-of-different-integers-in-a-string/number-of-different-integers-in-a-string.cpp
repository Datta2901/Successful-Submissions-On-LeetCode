class Solution {
public:
    int numDifferentIntegers(string word) {
        set<string> freq;
        for(int i = 0; i < word.size();i++){
            if(48 <= int(word[i]) && int(word[i])  <= 57){
                int j = i;
                string digit = "";
                while((48 <= int(word[j]) && int(word[j])  <= 57) && j < word.size()){
                    // cout << int(word[j]) << " at  : " <<  j <<  endl;
                    digit += word[j];
                    j++;
                }
                for(int k = 0; k < digit.size(); k++){
                    if(digit[k] == '0'){
                        digit.erase(digit.begin() + k);
                        k = -1;
                    }else{
                        break;
                    }
                }
                i = j - 1;
                // cout << digit << endl;
                freq.insert(digit);
            }
        
    }
        return freq.size();
    }
};