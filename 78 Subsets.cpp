class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> masks;
        vector<vector<int>> results;
        subsets(nums, masks, 0, results);
        return results;
    }
    void subsets(vector<int>& nums, vector<int>&mask, int index, vector<vector<int>>& results){
        // for(int i=0; i<mask.size(); i++)
        //     cout << mask.at(i) << " " ;
        // cout << " : " << index << endl;
        
        if(index == nums.size()){
            vector<int> result;
            for(int i=0; i<nums.size(); i++){
                if(mask.at(i)==1)
                    result.push_back(nums.at(i));
            }
            results.push_back(result);
            return;
        }
        mask.push_back(0);
        subsets(nums, mask, index+1, results);
        mask.pop_back();
        mask.push_back(1);
        subsets(nums, mask, index+1, results);
        mask.pop_back();
    }
};