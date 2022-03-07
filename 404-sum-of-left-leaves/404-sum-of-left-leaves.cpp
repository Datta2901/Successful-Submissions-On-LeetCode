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
    int sumOfLeftLeaves(TreeNode* root) {
        //Base condition         
        if(root == NULL){
            return 0;
        }
        // If we find Left node we simply traverse right child of the present node
        if(root->left && root->left->left == NULL && root->left->right == NULL){
            return root->left->val + sumOfLeftLeaves(root->right);
        }
        // else we will traverse both sides          
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};