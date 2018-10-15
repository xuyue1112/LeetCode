class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int _max = INT_MIN;
        int sum = 0;
        for(auto iter=nums.begin(); iter!=nums.end(); iter++){
            sum = max(sum+*iter, *iter);
            if(sum > _max)
                _max=sum;
        }
        return _max;
    }
};