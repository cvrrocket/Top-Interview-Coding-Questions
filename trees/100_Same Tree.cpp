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
    
    
//     vector<int> res1;
//     vector<int> res2;
//     void inorder(TreeNode *root, int toggle){
//         if(!root) {
//             // if(toggle==0){
//             //     res1.push_back(-1);//-1==null value
//             // }else{//toggle==1
//             //     res2.push_back(-1);
//             // }
//             return;
//         }
        
//         inorder(root->left, toggle);
//         if(toggle==0){
//             // if(root->left!=NULL && root->right!=NULL)
//             if(root->left==NULL && root->right==NULL){
//                 res1.push_back(root->val);
//             }else if(root->left==NULL && root->right!=NULL){
//                 res1.push_back(-1);//-1==null value
//                 res1.push_back(root->val);
//             }
//             else if(root->left!=NULL && root->right==NULL){
//                 res1.push_back(root->val);
//             }
//             else if(root->left!=NULL && root->right!=NULL){
//                 res1.push_back(root->val);
//             }
            
//         }else{//toggle==1
//             if(root->left==NULL && root->right==NULL){
//                 res2.push_back(root->val);
//             }else if(root->left==NULL && root->right!=NULL){
//                 res2.push_back(-1);//-1==null value
//                 res2.push_back(root->val);
//             }
//             else if(root->left!=NULL && root->right==NULL){
//                 res2.push_back(root->val);
//             }
//             else if(root->left!=NULL && root->right!=NULL){
//                 res2.push_back(root->val);
//             }
//         }
        
        
//         inorder(root->right, toggle);
//     }
    
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         inorder(p, 0);
//         inorder(q, 1);
//         // vector<int> v1=inorder(p, 0);
//         // vector<int> v2=inorder(q, 1);
//         return res1==res2;
//     }
// };

class Solution {
public:
    bool isSameTree(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL && root2==NULL) return true;
        if(root1==NULL || root2==NULL) return false;
        else{
            bool cond1 = root1->val == root2->val;
            bool cond2 = isSameTree(root1->left,root2->left);
            bool cond3 = isSameTree(root1->right,root2->right);
            if(cond1 && cond2 && cond3) return true;
        }
        return false;
    }
};
