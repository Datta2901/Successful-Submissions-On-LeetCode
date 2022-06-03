/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int a = p->val;
        int b = q->val;
        if(root == NULL || root->val == a || root->val == b){
            return root;
        }
        TreeNode* l = lowestCommonAncestor(root->left,p,q);
        TreeNode* r = lowestCommonAncestor(root->right,p,q);
        
        if(l == NULL){
            return r;
        }
        if(r == NULL){
            return l;
        }
        return root;
    }
};