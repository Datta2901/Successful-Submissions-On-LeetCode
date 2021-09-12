class Solution{
    public:
        int firstUniqChar(string s) {
            map<char,int>fre;
            for(auto i : s){
                fre[i]++;
            }
            int count = 0;
            for(auto i : s){
                // cout << i.first  << " " << i.second << endl;
                if(fre[i] == 1){
                    return count;
                }
                count++;
            }
            return -1;
        }
};
