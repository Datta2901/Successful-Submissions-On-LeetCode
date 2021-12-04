class StreamChecker {
    unordered_set<int> suffixHash, wordHash;
    string queryStream = "";
    int rollingHash(long& hash, long& p_pow, char c) {
        p_pow = (p_pow * 31) % 1000000007;
        return hash = (hash + (c-'a'+1) * p_pow) % 1000000007;
    }
public:    
    StreamChecker(vector<string>& words) { 
        for(auto& w : words) {
            long hash = 0, p_pow = 1;
            for(int i = size(w)-1; ~i; i--) 
                suffixHash.insert(rollingHash(hash, p_pow, w[i]));                          
            wordHash.insert(hash);                                                          
        }
    }
    bool query(char c) {
        queryStream += c;
        for(long i = size(queryStream)-1, hash = 0, p_pow = 1; ~i; i--){          
            if(!suffixHash.count(rollingHash(hash, p_pow, queryStream[i]))){
                return false;
            }else if(wordHash.count(hash)){
               return true; 
            } 
        }  
        
        return false;
    }
};