// 方法一
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        // for(auto iter = nums.begin(); iter != nums.end(); iter++){
        //     cout << *iter << endl;
        // }
        int size = 0;
        
        vector<int> tmp;
        ret.push_back(tmp);
        // for(auto iter = ret.begin(); iter != ret.end(); iter++){
        //     for(auto iter2 = (*iter).begin(); iter2 != (*iter).end(); iter2++){
        //         cout << *iter2 << " ";
        //     }
        //     cout << endl;
        // }
        for(int i=0; i<nums.size(); i++){
            int startIndex = 0;
            if(i>0 && nums[i] == nums[i-1]){
                startIndex = size;
            }
            else{
                startIndex = 0;
            }
            size = ret.size();
            
            
            for(int j=startIndex; j<size; j++){
                auto tmp = ret[j];
                tmp.push_back(nums[i]);
                ret.push_back(tmp);
            }
            // for(auto iter = ret.begin(); iter != ret.end(); iter++){
            //     for(auto iter2 = (*iter).begin(); iter2 != (*iter).end(); iter2++){
            //         cout << *iter2 << " ";
            //     }
            //     cout << endl;
            // }
        }
        
        
        
    return ret;
    }
};

//方法二




