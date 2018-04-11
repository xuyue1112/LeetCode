#include "vector"
#include "iostream"
#include "algorithm"
using namespace std;
int MaxProfit(vector<int>& prices){
	int minPrice = INT_MAX;
	int maxProfit = 0;
	for (int i = 0; i < prices.size(); i++){
		if (prices.at(i) < minPrice)
			minPrice = prices.at(i);
		else if (prices.at(i) - minPrice> maxProfit){
			maxProfit = prices.at(i) - minPrice;
		}
	}
	return maxProfit;
}
int main(){
	int num;
	vector<int> prices;
	cin >> num;
	int tmpInt;
	for (int i = 0; i < num; i++){
		cin >> tmpInt;
		prices.push_back(tmpInt);
	}
	cout << MaxProfit(prices);
	system("pause");
}
