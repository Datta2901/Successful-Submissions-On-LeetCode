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
    int answer;
    int MaxHeight(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int left = MaxHeight(root->left);
        int right = MaxHeight(root->right);
        answer = max(answer,left + right + 1);
        return (max(left,right) + 1);
    }    
    int diameterOfBinaryTree(TreeNode* root) {
        answer = INT_MIN;
        MaxHeight(root);
        return answer - 1;
    }
};