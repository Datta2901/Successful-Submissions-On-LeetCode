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
class Solution {
private:
    vector<vector<int> > answer;
    vector<int>path;
    void StorePath(TreeNode* root,int target){
        if(root == NULL){
            return;
        }
        path.push_back(root->val);
        if(root && root->left == NULL && root->right == NULL && target - root->val == 0){
            answer.push_back(path);
            path.pop_back();
            return;
        }
        StorePath(root->left,target - root->val);
        StorePath(root->right,target - root->val); 
        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        StorePath(root,targetSum);
        return answer;
    }
};