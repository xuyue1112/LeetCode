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
    void buildTree(int start, int end, TreeNode* root, vector<int>& inorder, vector<int>& postorder){
        if(end==start){
            return;
        }
        int indexRightNode = start-1, indexLeftNode = start-1;
        
        auto pRoot = find(inorder.begin(), inorder.end(), root->val);
        
        
        auto tmp = find(inorder.begin(), inorder.end(), postorder[end-1]);
        if(tmp > pRoot){
            indexRightNode = end-1;
            for(int i=end-1; i>=start; i--){
                tmp = find(inorder.begin(), inorder.end(), postorder[i]);
                if(tmp < pRoot){
                    indexLeftNode = i;
                    break;
                }
            }
        }
        else if(tmp < pRoot){
            indexLeftNode = end-1;
        }
        else{
            cout << "inpossible!" << endl;
        }
        
        if(indexLeftNode >= start){
            TreeNode* left = new TreeNode(postorder[indexLeftNode]);
            root->left = left;
            buildTree(start, indexLeftNode, left, inorder, postorder);
        }
        if(indexRightNode>=start){
            TreeNode* right = new TreeNode(postorder[indexRightNode]);
            root->right = right;
            buildTree(indexLeftNode+1, indexRightNode, right, inorder, postorder);
        }
        
    };
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()==0)
            return NULL;
        TreeNode* root = new TreeNode(*(postorder.end()-1));
        buildTree(0, postorder.size()-1, root, inorder, postorder);
        return root;
    }
};