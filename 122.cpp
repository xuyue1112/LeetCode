class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price=INT_MAX;
        //int max_index=-1;
        int max_profit=0;
        //bool could_buy = true;
        for(auto iter=prices.begin(); iter!=prices.end(); iter++){
            
            if(*iter<min_price){
                min_price = *iter;
            }
            if(*iter - min_price > 0){
                max_profit += *iter - min_price;
                min_price = *iter;
                //max_index = iter-prices.begin();
            }
        }
        return max_profit;
    }
};