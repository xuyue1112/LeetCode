/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        TreeNode *left, *right;
        
        left = root->left;
        right = root->right;
        if(left==NULL){
            if(right!=NULL) return false;
        }
        if(right==NULL){
            if(left!=NULL) return false;
        }
        if(left==NULL and right==NULL)
            return true;
        return recursively(left,right);
    }
    bool recursively(TreeNode* left, TreeNode*right){
        if(left->val != right->val)
            return false;
        if(left->left != NULL){
            if(right->right == NULL){
                return false;
            }
            if(false == recursively(left->left, right->right))
                return false;
        }
        if(left->right != NULL){
            if(right->left == NULL){
                return false;
            }
            if(false == recursively(left->right, right->left))
                return false;
        }
        if(left->left==NULL)
            return right->right==NULL;
        if(left->right==NULL)
            return right->left==NULL;
        return true;
    }
};
