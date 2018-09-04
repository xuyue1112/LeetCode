class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL)
            return NULL;
        vector<vector<int>> ret;
        vector<TreeNode*> pOneLevel_old;
        vector<TreeNode*> pOneLevel_new;
        vector<int> iOneLevel;
        pOneLevel.push_back(root);
        iOneLevel.push_back(root->val)
            
        for(bool findSon=false; findSon==true;){
            for(auto iter=pOneLevel.begin(); iter!=pOneLevel.end(); iter++){
                if((*iter)->left !=NULL){
                    findSon = true;
                    pOne
            }
    }
};
