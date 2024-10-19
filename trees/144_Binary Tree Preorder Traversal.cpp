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
    vector<int> ans;
    vector<int> preorderTraversal(TreeNode* root) {
        preorderTraversalUtil(root, ans);
        return ans;
    }
private:
    void preorderTraversalUtil(TreeNode* root, vector<int>& ans) {
        // if(root==NULL)
            // return
        if(root!=NULL){
            ans.push_back(root->val);
            preorderTraversalUtil(root->left, ans);
            preorderTraversalUtil(root->right, ans);
        }
        return;
    }
};
