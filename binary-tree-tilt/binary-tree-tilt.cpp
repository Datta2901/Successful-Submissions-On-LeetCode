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
   int answer;
   int tilt(TreeNode* root){
       if(root == NULL){
            return 0;
        }
        int leftSub =  tilt(root->left);
        int rightSub = tilt(root->right);
        answer += abs(leftSub - rightSub); 
        return leftSub + rightSub + root->val;
   }
public:
    int findTilt(TreeNode* root) {
        answer = 0;
        tilt(root);
        return answer;
    }
};