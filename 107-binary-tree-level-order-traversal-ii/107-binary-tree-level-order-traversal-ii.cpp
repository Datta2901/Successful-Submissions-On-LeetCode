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
    vector<int>level;
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == NULL){
            return answer;
        }
        queue<TreeNode*> store;
        store.push(root);
        store.push(NULL);
        while(!store.empty()){
            TreeNode* node = store.front();
            store.pop();
            if(node){
                level.push_back(node->val);
                if(node->left){
                    store.push(node->left);
                }
                if(node->right){
                    store.push(node->right);
                }
            }else if(node == NULL && !store.empty()){
                store.push(NULL);
                answer.push_back(level);
                level.clear();
            }
        }
        answer.push_back(level);
        reverse(answer.begin(),answer.end());
        return answer;
    }
};