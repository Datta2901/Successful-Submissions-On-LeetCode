class Solution {
    vector<int>answer;
    void LevelOrder(TreeNode* root){
        queue<TreeNode*> track;
        track.push(root);
        track.push(NULL);
        int prev = 0;
        while(!track.empty()){
            TreeNode* node = track.front();
            track.pop();
            if(node){
                prev = node->val;
                if(node->left){
                    track.push(node->left);
                }if(node->right){
                    track.push(node->right);
                }
            }else if(node == NULL && !track.empty()){
                answer.push_back(prev);
                track.push(node);
            }
        }
        answer.push_back(prev);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        LevelOrder(root);
        return answer;
    }
};
