class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int answer = 0;
        for(int i = 1; i < n - 1; i++){
            int water = min(*max_element(height.begin(),height.begin() + i),*max_element(height.begin() + i + 1,height.end()));
            answer +=  (water - height[i]  > 0) ? water - height[i] : 0;
            // cout << i << " -> " << water << " "  << height[i] << endl;
        }
        return answer;
    }
};
