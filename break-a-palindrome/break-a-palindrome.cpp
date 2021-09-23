class Solution {
public:
    string breakPalindrome(string palindrome) {
        int size = palindrome.size();
        if(size == 1){
            return "";
        }
        char replace = 'a';
        int i = 0;
        for(i = 0; i < size; i++){
            if(palindrome[i] != 'a' && i != size - i - 1){
                palindrome[i] = replace;
                break;
            }
        }
        if(i == size){
            palindrome[i - 1] = replace + 1;
        }
        return palindrome;
    }
};