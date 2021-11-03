class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string,int>fre;
        for(auto it : arr){
            fre[it]++;
        }
        int count = 0;
        for(auto it : arr){
            if(fre[it] == 1){
                count++;
                cout << count << endl;
                if(count == k){
                    return it;
                }
            }
        }
        return "";  
    }
};