class Solution {
public:
    double myPow(double x, int n) {
        // stl         
        // double answer = pow(x,n);
        double answer = 1;
        long int times = n;
        if(times < 0){
            times = -times;
        }
        while(times > 0){
            if(times % 2 == 1){
                answer = answer * x;
                times -= 1;
            }else{
                 x = x * x;
                 times /= 2;
            }
        }
        if(n < 0){
            answer = 1.0 / answer;
        }
        return answer;
    }
};