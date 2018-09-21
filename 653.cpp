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
    vector<pair<TreeNode*, int>> increase;
    vector<pair<TreeNode*, int>> decrease;
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL)
            return false;
        TreeNode* cur_in = root;
        TreeNode* cur_de = root;
        increase.push_back(make_pair(cur_in, 0)); //0:未遍历左子树 1:未遍历自己 2:未遍历右子树
        decrease.push_back(make_pair(cur_de, 0));
        int curInt_in, curInt_de;
        curInt_in = loadNext_in();
        curInt_de = loadNext_de();
        // cout << curInt_in << " " << curInt_de << endl;
        while(increase.back().first != decrease.back().first){
            // cout << curInt_in << " " << curInt_de << endl;
            if(curInt_in + curInt_de < k){
                curInt_in = loadNext_in();
                continue;
            }
            if(curInt_in + curInt_de == k){
                return true;
            }
            if (curInt_in + curInt_de > k){
                curInt_de = loadNext_de();
                continue;
            }
        }
        return false;
    };
    int loadNext_in(){
        auto tmp = increase[increase.size()-1];
        // cout << "in " << tmp.first->val << endl; 
        if(increase[increase.size()-1].second==0 ){
            increase[increase.size()-1].second=1;
            if( increase[increase.size()-1].first->left != NULL){
                increase.push_back(make_pair(increase[increase.size()-1].first->left, 0));
                return loadNext_in();
            }
        }
        if(increase[increase.size()-1].second==1){
            increase[increase.size()-1].second=2;
            return increase[increase.size()-1].first->val;
        }
        if(increase[increase.size()-1].second==2 ){
            increase[increase.size()-1].second=3;
            if( increase[increase.size()-1].first->right != NULL){
                increase.push_back(make_pair(increase[increase.size()-1].first->right, 0));
                return loadNext_in();
            }
        }
        if(increase[increase.size()-1].second==3){
            increase.pop_back();
            return loadNext_in();
        }
    }
    int loadNext_de(){
        auto tmp = decrease[decrease.size()-1];
        // cout << "de " << tmp.first->val << " " << tmp.second << endl; 
        if(decrease[decrease.size()-1].second==0 ){
            decrease[decrease.size()-1].second=1;
            if(decrease[decrease.size()-1].first->right != NULL){
                decrease.push_back(make_pair(decrease[decrease.size()-1].first->right, 0));
                return loadNext_de();
            }
        }
        if(decrease[decrease.size()-1].second==1){
            decrease[decrease.size()-1].second=2;
            // cout << "aaa" << decrease[decrease.size()-1].second << endl;
            return decrease[decrease.size()-1].first->val;
        }
        if(decrease[decrease.size()-1].second==2 ){
            // cout << "ccc" << endl;
            decrease[decrease.size()-1].second=3;
            if(decrease[decrease.size()-1].first->left != NULL){
                decrease.push_back(make_pair(decrease[decrease.size()-1].first->left, 0));
                return loadNext_de();
            }   
        }
        if(decrease[decrease.size()-1].second==3){
            // cout << "bbb" << endl;
            decrease.pop_back();
            return loadNext_de();
        }
    }
};