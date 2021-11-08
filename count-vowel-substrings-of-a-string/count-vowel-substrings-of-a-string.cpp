class Solution{
    private:
        bool isVowel(char a){
            if(a == 'a' || a == 'e' ||a == 'i' ||a == 'o' ||a == 'u'){
                return true;
            }
            return false;
        }
    public:
        int countVowelSubstrings(string word) {
            int n = word.size();
            int answer = 0;
            for(int i = 0; i < n; i++){
                set<int>store;
                for(int j = i; j < n; j++){
                    if(isVowel(word[j])){
                        store.insert(word[j]);
                        if(store.size() == 5){
                            answer++;
                        }
                    }else{
                        break;
                    }
                }
            }
            return answer;
        }
};