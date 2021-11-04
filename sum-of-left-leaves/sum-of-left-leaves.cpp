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
public:
    
    int CountLeftLeaves(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        if(root->left && root->left->left == NULL && root->left->right == NULL){
            return root->left->val + CountLeftLeaves(root->right);
        }
        return CountLeftLeaves(root->left) + CountLeftLeaves(root->right);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        return CountLeftLeaves(root);
    }
};