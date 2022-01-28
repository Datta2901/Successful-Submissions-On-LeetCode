class WordDictionary {
private:
    unordered_map<int,vector<string> > store;
        
    bool isEqual(string a,string b){
        int n = a.size();
        for(int i = 0; i < n; i++){
            if(b[i] == '.'){
                continue;
            }else if(a[i] != b[i]){
                return false;
            }
        }
        return true;
    }
    
public:  
    void addWord(string word) {
        store[word.size()].push_back(word);
    }
    
    bool search(string word) {
        for(auto it : store[word.size()]){
            if(isEqual(it,word)){
                return true;
            }
        }
        return false;
    }
    
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */