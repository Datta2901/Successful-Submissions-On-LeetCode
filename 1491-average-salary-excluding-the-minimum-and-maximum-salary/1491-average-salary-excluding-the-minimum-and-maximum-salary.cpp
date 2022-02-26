class Solution {
public:
    double average(vector<int>& salary) {
        int mini = *min_element(salary.begin(),salary.end());
        int maxi = *max_element(salary.begin(),salary.end());
        int sum = accumulate(salary.begin(),salary.end(),0);
        int n = salary.size() - 2;
        sum = sum - maxi - mini;
        double mean = double(sum) / n;
        return mean;
    }
};