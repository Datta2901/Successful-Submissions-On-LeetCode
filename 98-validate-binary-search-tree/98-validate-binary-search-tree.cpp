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
    vector<int>Inorder;
    void inorder(TreeNode* root){
        if(root){
            inorder(root->left);
            Inorder.push_back(root->val);
            inorder(root->right);
        }
    }
public:    
    bool isValidBST(TreeNode* root) {
        inorder(root);
        for(auto it : Inorder){
            cout << it << " ";
        }
        cout << endl;
        int n = Inorder.size();
        for(int i = 1; i < n; i++){
            if(Inorder[i - 1] >= Inorder[i]){
                return false;
            }
        }
        return true;
    }
};