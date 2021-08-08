class Solution {
public:
    void nextPermutation(vector<int>& numbers) {
        //         using stl
        // std::next_permutation(nums.begin(),nums.end());
        int i = numbers.size() - 2;
        while (i >= 0 && numbers[i + 1] <= numbers[i]) {
            i--;
        }
        if (i >= 0) {
            int j = numbers.size() - 1;
            while (numbers[j] <= numbers[i]) {
                j--;
            }
            swap(numbers[i],numbers[j]);
        }
        reverse(numbers.begin() + i + 1,numbers.end());
        }
};