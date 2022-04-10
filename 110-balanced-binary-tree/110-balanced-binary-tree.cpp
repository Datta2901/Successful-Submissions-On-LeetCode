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
// class Solution {
//     bool ans;
//     int height(TreeNode* root){
//         if(root == NULL){
//             return 0;
//         }
//         if(ans == false){
//             return 0;
//         }
//         int hl = height(root->left);
//         int hr = height(root->right);
//         if(abs(hl - hr) > 1){
//             ans = false;
//         }
//         return 1 + max(height(root->left),height(root->right));
//     }
    
// public:
//     bool isBalanced(TreeNode* root) {
//         ans = true;
//         int l = height(root);
//         return ans;
//     }
// };

class Solution {
    bool answer;
    int height(TreeNode* root){
        if(!root){
            return 0;
        }
        int l = height(root->left);
        int r = height(root->right);
        if(abs(l - r) > 1){
            answer = false;
            return false;
        }
        return 1 + max(l,r);
    }
    
public:
    bool isBalanced(TreeNode* root) {
        answer = true;
        height(root);
        return answer;
    }
};