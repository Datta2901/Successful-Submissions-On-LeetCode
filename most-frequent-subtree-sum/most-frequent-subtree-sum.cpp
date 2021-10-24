/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution{
    private:
        unordered_map<int,int> fre;
        vector<int>answer;
        int maximum;
    public:
        vector<int> findFrequentTreeSum(TreeNode* root) {
            maximum = 0;
            dfs(root);
            for(auto it : fre){
                if(it.second == maximum){
                    answer.push_back(it.first);
                }
            }
            return answer;
        }

        int dfs(TreeNode* root){
            if(root == NULL){
                return 0;
            }
            int sum = dfs(root->left) + dfs(root->right) + root->val;
            fre[sum]++;
            maximum = max(maximum,fre[sum]);
            return sum;
        }
};
