#include "vector"
#include "iostream"
#include "algorithm"
using namespace std;
int minCostClimbingStairs(vector<int>& cost){
	int height = cost.size();
	if (height == 1){
		return cost.at(0);
	}
	else if (height == 2){
		return cost.at(0) + cost.at(1);
	}
	else if (height == 0){
		return 0;
	}
	vector<int> min_cost;
	min_cost.push_back(0);
	min_cost.push_back(0);
	for (int i = 2; i <= height; i++){
		min_cost.push_back(min(min_cost.at(i-1)+cost.at(i-1), min_cost.at(i-2)+cost.at(i-2)) );
	}
	return min_cost.at(height);
}
int main(){
	vector<int> cost;
	int num;
	int input;
	cin >> num;
	for (int i = 0; i < num; i++){
		cin >> input;
		cost.push_back(input);
	}
	cout << minCostClimbingStairs(cost);
	system("pause");
}