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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(root==NULL)
            return ret;
        vector<TreeNode*> pOneLevel_old;
        vector<TreeNode*> pOneLevel_new;
        vector<int> iOneLevel;
        pOneLevel_old.push_back(root);
        iOneLevel.push_back(root->val);
        ret.push_back(iOneLevel);
        for(bool findSon=true; findSon==true;){
            findSon=false;
            iOneLevel.clear();
            pOneLevel_new.clear();
            for(auto iter=pOneLevel_old.begin(); iter!=pOneLevel_old.end(); iter++){
                if((*iter)->left !=NULL){
                    findSon = true;
                    pOneLevel_new.push_back((*iter)->left);
                    iOneLevel.push_back((*iter)->left->val);
                }
                if((*iter)->right !=NULL){
                    findSon = true;
                    pOneLevel_new.push_back((*iter)->right);
                    iOneLevel.push_back((*iter)->right->val);
                }
            }
            if(findSon) 
                ret.push_back(iOneLevel);
            pOneLevel_old = pOneLevel_new;
        }
        return ret;
    }
};
