class Solution {
public:
    int numSquares(int n) {
        int leastNum[n+1];
        memset(leastNum, INT_MAX, n+1);
        leastNum[0] = 0;
        for(int i=1; i<=n; i++){
            int _min = INT_MAX;
            for(int j=1; j*j <= i; j++){
                _min = min(_min, leastNum[i-j*j]+1);
            }
            leastNum[i] = _min;
        }
        return leastNum[n];
    }
    
};