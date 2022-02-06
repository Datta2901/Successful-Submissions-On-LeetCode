/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->f();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->cnt();
 * string param_7 = obj->toString();
 */

class Bitset {
public:
    vector<int>bit;
    bool f;
    int cnt;
    Bitset(int size) {
        bit.resize(size);
        f = false;
        cnt = 0;
    }
    
    void fix(int idx) {
        if(!f){
            if(bit[idx] == 0){
                bit[idx] = 1;
                cnt++;
            }
        }else{
            if(bit[idx] == 1){
                cnt++;
                bit[idx] = 0;
            }             
        }
    }
    
    void unfix(int idx) {
        if(!f){
            if(bit[idx] == 1){
                bit[idx] = 0;
                cnt--;
            }
        }else{
            if(bit[idx] == 0){
                cnt--;
                bit[idx] = 1;
            }             
        }
    }
    
    void flip() {
        f = !f;
        cnt = bit.size() - cnt;
    }
    
    bool all() {
        return cnt == bit.size();
    }
    
    bool one() {
        return cnt >= 1;
    }
    
    int count() {
        return cnt;
    }
    
    string toString() {
        string answer = "";
        if(!f){
            for(auto it : bit){
                if(it == 0){
                    answer += '0';
                }else{
                    answer += '1';
                }
            }
        }else{
            for(auto it : bit){
                if(it == 0){
                    answer += '1';
                }else{
                    answer += '0';
                }
            }
        }
        return answer;
    }
};