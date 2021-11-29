class Solution {
private:
    vector<vector<int>> answer;
    void binarySearch(vector<int>&num,int index){
        int n = num.size();
        int low = index + 1,high = n - 1;
        int sum = 0 - num[index];
        while(low < high){
            if(num[low] + num[high] == sum){
                answer.push_back({num[low],num[high],num[index]});
                while(low < high && num[low] == num[low + 1]){
                    low++;
                }
                while(low < high && num[high] == num[high - 1]){
                    high--;
                }
                low++,high--;
            }else if(num[low] + num[high] < sum){
                low++;
            }else{
                high--;
            }
        }
    }
public:
    vector<vector<int>> threeSum(vector<int>& num) {
        
        //Using three pointers
        int n = num.size();
        if(n == 0){
            return answer;
        }
        sort(num.begin(),num.end());
        for(int i = 0; i < n - 2; i++){
            // i - one pointer             
            if(i == 0 || (num[i] != num[i - 1])){
                // doing binary search on other side
                // We have to avoid duplicates 
                binarySearch(num,i);
            }
        }
        return answer;
    }
};