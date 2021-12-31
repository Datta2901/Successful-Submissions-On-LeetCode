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
    int getAnswer(TreeNode*root,int maxi = 0,int mini = 1000000){
        if(root == NULL){
            return (maxi - mini);
        }
        maxi = max(maxi,root->val);
        mini = min(mini,root->val);
        return max(getAnswer(root->left,maxi,mini),getAnswer(root->right,maxi,mini));
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        return getAnswer(root);
    }
};