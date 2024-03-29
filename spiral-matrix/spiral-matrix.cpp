class Solution {
public:
    vector<int> answer;
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        int m = matrix.size(),n = matrix[0].size();
        int left = 0,right = n - 1,top = 0,down = m - 1;
        int dir = 0;
        while(left <= right && top <= down){
            if(dir == 0){
                for(int i = left; i <= right; i++){
                    answer.push_back(matrix[top][i]);
                }
                top += 1;

            }else if(dir == 1){
                for(int i = top; i <= down; i++){
                    answer.push_back(matrix[i][right]);
                }
                right -= 1;

            }else if(dir == 2){
                for(int i = right; i >= left; i--){
                    answer.push_back(matrix[down][i]);
                }
                down -= 1;
            }else if(dir == 3){
                for(int i = down; i >= top; i--){
                    answer.push_back(matrix[i][left]);
                }
                left += 1;
            }
            dir = (dir + 1) % 4;
        }
        return answer;
    }
};
