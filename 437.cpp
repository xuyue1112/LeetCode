class Solution {
public:
    int count=0;
    void calcPathSum(TreeNode* start, int& sum, int curSum){
        if(start==NULL){
            return;
        }
        if(curSum+start->val==sum){
            count++;
        }
        
        
        calcPathSum(start->left, sum, curSum+start->val);
        calcPathSum(start->right, sum, curSum+start->val);
        return;
    };
    int pathSum(TreeNode* root, int sum) {
        
        if(root==NULL)
            return 0;
        pathSum(root->left, sum);
        pathSum(root->right, sum);
        if(root->val==sum)
            count++;
        calcPathSum(root->left, sum, root->val);
        calcPathSum(root->right, sum, root->val);
        return count;
    }
};