class Solution {
public:
    string addStrings(string num1, string num2) {
        string result;
        int a,b,sum,carry=0;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        while(i>=0 || j>=0){
            a = (i>=0) ? num1[i]-'0' : 0; 
            b = (j>=0) ? num2[j]-'0' : 0; 
            sum = a+b+carry;
            carry = sum/10;
            sum = sum%10;
            result.push_back('0' + sum);
            i--;
            j--;
        }
        
        if(carry)
            result.push_back('0' + carry);
        reverse(result.begin(),result.end());
        return result;
    }
};