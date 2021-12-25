class Solution {
public:
    int calculate(string s) {
        int size = s.size();
        if(size == 0){
            return 0;
        }
        stack<int>store;
        int num = 0;
        int answer = 0;
        char operation = '+';
        for(int i = 0; i < size; i++){
            char current = s[i];
            if(isdigit(current)){
                num = num * 10  + (current - '0');
            }if(!isdigit(current) && !iswspace(current) || i == size - 1){
                if(operation == '-'){
                    store.push(-num);
                }else if(operation == '+'){
                    store.push(num);
                }else if(operation == '*'){
                    int top = store.top();
                    store.pop();
                    store.push(top * num);
                }else if(operation == '/'){
                     int top = store.top();
                     store.pop();
                     store.push(top / num);
                }
                operation = current;
                num = 0;
            }
        }
        while(!store.empty()){
            answer += store.top();
            store.pop();
        }
        return answer;
    }
};