class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int answer = 0;
        while(target > startValue){
            if(target % 2 == 1){
                target += 1;
            }else{
                target /= 2;
            }
            answer++;
        }
        
        return answer + startValue - target;
    }
};