class Solution {
    string getSub(int start,int end,string s){
        string answer = "";
        for(int i = start; i < end; i++){
            answer += (s[i]);
        }
        return answer;
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>answer;
        string digits = "123456789";
        int dl = log10(low) + 1;
        int dh = log10(high) + 1;
        for(int i = dl; i <= dh; i++){
            for(int j = 0; j < 9; j++){
                if(j + i <= 9){
                    int num = stoi(digits.substr(j,i));
                    // int num = stoi(getSub(j,j + i,digits));
                    // cout << num << endl;
                    if(low <= num && num <= high){
                        answer.push_back(num);
                    }
                }
            }
        }
        return answer;
    }
};