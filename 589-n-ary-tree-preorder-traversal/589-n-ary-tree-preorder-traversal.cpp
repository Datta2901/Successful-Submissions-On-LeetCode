/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

// class Solution {
//     vector<int>answer;
//     void pre(Node* root){
//         if(root == NULL){
//             return;
//         }
//         answer.push_back(root->val);
//         for(auto it : root->children){
//             pre(it);
//         }
//     }
// public:
//     vector<int> preorder(Node* root) {
//         pre(root);
//         return answer;
//     }
// };



class Solution {
    vector<int>answer;
    void traverse(Node* root){
        if(!root){
            return;
        }
        answer.push_back(root->val);
        for(auto it : root->children){
            traverse(it);
        }
    }
public:
    vector<int> preorder(Node* root) {
        traverse(root);
        return answer;
    }
};