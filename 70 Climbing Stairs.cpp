#include "vector"
#include "iostream"
using namespace std;
int climbStairs(int n) {
    vector<int> minSteps;
    minSteps.push_back(1);
    minSteps.push_back(1);
    for(int i=2; i<n; i++){
        minSteps.push_back(minSteps.at(i-2) + minSteps.at(i-1));
    }
    cout << minSteps.at(minSteps.size()-1) << endl;
    return 0;
}
int main(){
    cout << "hello world" << endl;
    climbStairs(10);
    return 0;
}