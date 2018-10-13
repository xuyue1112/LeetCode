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
    TreeNode* recursion(TreeNode* node, TreeNode* cur){ //node:current node of output; cur:current node of input
        if(cur==NULL)
            return node;
        //cout << cur->val << endl;
        node = recursion(node, cur->left);
        node->right=cur;
        //node->left=NULL;
        node = node->right;
        node->left=NULL;
        node = recursion(node, cur->right);
        node->right=NULL;
        return node;
    };
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* head = new TreeNode(0);
        recursion(head, root);
        TreeNode* tmp = head->right;
        // cout << endl;
        // while(tmp != NULL){
        //     cout << tmp->val << endl;
        //     tmp = tmp->right;
        // }
        return head->right;
    }
};