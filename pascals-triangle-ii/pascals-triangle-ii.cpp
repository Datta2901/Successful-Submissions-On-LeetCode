// This is not the ideal solution
// Due to generating all the above rows of given kth row 
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>pascal(rowIndex + 1);
        for(int i = 0; i <= rowIndex; i++){
            pascal[i].resize(i + 1);
            pascal[i][0] = 1;
            pascal[i][i] = 1;
            for(int j = 1; j < i; j++){
                pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
            }
        }
        return pascal[rowIndex];
        
    }
};


// Efficient solution follows as
// By using the formula 
// given r and c are the row and column
// r - 1 C
//          c - 1
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        //By Using Combinations
        vector<int>answer;
        long long int nCr = 1;
        answer.push_back(nCr);
        rowIndex += 1;// 1 based
        for(int i = 1; i < rowIndex; i++){
            nCr = nCr * (rowIndex - i);
            nCr = nCr / i;
            answer.push_back(nCr);
        }
        return answer;
    }
};
