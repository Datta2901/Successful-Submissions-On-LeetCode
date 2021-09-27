class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string>fre;
        string a = "";
        for(int i = 0; i < emails.size(); i++){
            int control = 0;
            for(int j = 0; j < emails[i].size(); j++){
                if((control == 1 || control == 0) && emails[i][j] == '@' ){
                    control = 2;
                }else if(emails[i][j] == '.' && control != 2){
                    continue;
                }else if(emails[i][j] == '+'){
                    control = 1;
                    continue;
                }else if(control == 1){
                    continue;
                }
                a += emails[i][j];
            }
            fre.insert(a);
            cout << a << endl;
            a = "";
        } 
        return fre.size();
    }
};