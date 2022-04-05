class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int Min = INT_MAX;
        int answer = INT_MIN;
        while(left < right){
            Min = min(height[right],height[left]);
                                        //width * height
            answer = max(answer,(Min * (right - left)) );
            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }
        return answer;
    }
};