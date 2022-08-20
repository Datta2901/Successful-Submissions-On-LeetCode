class Solution {
public:
    int romanToInt(string numeral) {
       unordered_map<char,int>fre;
        fre['I'] = 1;
        fre['V'] = 5;
        fre['X'] = 10;
        fre['L'] = 50;
        fre['C'] = 100;
        fre['D'] = 500;
        fre['M'] = 1000;
        int count = 0;
        int size = numeral.size();
        for(int i = 0; i < size; i++){
            if(i + 1 < size && numeral[i] == 'I' && numeral[i + 1] == 'V'){
                count += 4;
                i++;
            }else if(i + 1 < size && numeral[i] == 'I' && numeral[i + 1] == 'X'){
                count += 9;
                i++;
            }else if(i + 1 < size && numeral[i] == 'X' && numeral[i + 1] == 'L'){        i++;
                count += 40;
            }

            else if(i + 1 < size && numeral[i] == 'X' && numeral[i + 1] == 'C'){        i++;
                count += 90;
            }
            else if(i + 1 < size && numeral[i] == 'C' && numeral[i + 1] == 'D'){        i++;
                count += 400;
            }
            else if(i + 1 < size && numeral[i] == 'C' && numeral[i + 1] == 'M'){
                count += 900;
                i++;
            }else{
                count += fre[numeral[i]];
            }
        }
        return count; 
    }
};