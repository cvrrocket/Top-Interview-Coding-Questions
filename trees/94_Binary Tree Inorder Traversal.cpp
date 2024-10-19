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
// public:
//     vector<int> ans;
//     vector<int> inorderTraversal(TreeNode* root) {
//         inorderUtil(root, ans);
//         return ans;
//     }
// private:
//     void inorderUtil(TreeNode* root, vector<int>& ans) {
//         // if(root==NULL)
//             // return
//         if(root!=NULL){
//             inorderTraversal(root->left);
//             ans.push_back(root->val);
//             inorderTraversal(root->right);
//         }
//         return;
//     }
// };

class Solution {
public:
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        inorderUtil(root, ans);
        return ans;
    }
private:
    void inorderUtil(TreeNode* root, vector<int>& ans) {
        // if(root==NULL)
            // return
        if(root!=NULL){
            inorderUtil(root->left, ans);
            ans.push_back(root->val);
            inorderUtil(root->right, ans);
        }
        return;
    }
};
