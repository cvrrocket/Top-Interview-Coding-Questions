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
    TreeNode* dfs(TreeNode *root){
        // if(root->left==NULL and root->right==NULL) return root;
        if(root==NULL) return NULL;
        
        TreeNode *tmp=root->left;
        root->left=dfs(root->right);
        root->right=dfs(tmp);//dfs(root->left);
        return root;
    }
    
    TreeNode* invertTree(TreeNode* root) {
        return dfs(root);
    }
};

/*
void helper(TreeNode* root){
        if(root == NULL)
            return;
        TreeNode* tem;
        tem =  root->right;
        root->right = root->left;
        root->left = tem;
        invertTree(root->left);
        invertTree(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
    }
*/

/*
var invertTree = function(root) {
    
    const stack = [root];
    
    while(stack.length){
        
        const node = stack.pop();
        
        if(node != null){
            
            stack.push(node.left);
            stack.push(node.right);
            
            const temp = node.left;
            node.left = node.right;
            node.right = temp;
        }
    }
    return root;
};
*/

/*
TreeNode* invertTree(TreeNode* root) 
    {
          if(root==NULL)
              return root;
        
        invertTree(root->left);
        invertTree(root->right);
        
        swap(root->left,root->right);
        
        return root;
        
    }
*/
