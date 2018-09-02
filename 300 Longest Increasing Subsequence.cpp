class Solution {
public:
    int specialBinarySearch(vector<int>& dp, int& length, int num){
        int i = 0;
        int j = length;
        int m;
        while(i != j){
            m = (i+j) / 2;
            if(dp[m] < num){
                i = m+1;
            }
            else{
                j = m;
            }
        }
        return i;
    };
    
    int lengthOfLIS(vector<int>& nums) {
        int length = 0;
        vector<int> dp;
        for(int i=0; i<nums.size(); i++)
            dp.push_back(0);
        for(int i=0; i<nums.size(); i++){
            int index = specialBinarySearch(dp, length, nums[i]);
            dp[index] = nums[i];
            if(index==length){
                length += 1;
            }
        }
        return length;
    }
};