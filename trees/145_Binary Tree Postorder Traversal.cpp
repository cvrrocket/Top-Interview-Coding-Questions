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
    vector<int> postorderTraversal(TreeNode* root) {
        postorderTraversalUtil(root, ans);
        return ans;    
    }
private:
    void postorderTraversalUtil(TreeNode* root, vector<int>& ans) {
        // if(root==NULL)
            // return
        if(root!=NULL){
            postorderTraversalUtil(root->left, ans);
            postorderTraversalUtil(root->right, ans);
            ans.push_back(root->val);
        }
        return;
    }
};
