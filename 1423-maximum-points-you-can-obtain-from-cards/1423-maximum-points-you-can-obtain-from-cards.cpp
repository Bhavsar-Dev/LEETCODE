class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        if(k == n) {
            return accumulate(cardPoints.begin(), cardPoints.end(), 0);
        }
        int len = n - k;
        int tot = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        int sum = 0;
        for(int i = 0; i < len; ++i) {
            sum += cardPoints[i];
        } 
        int mn = sum;
        for(int i = len; i < n; ++i) {
            sum += cardPoints[i];
            sum -= cardPoints[i - len];
            mn = min(mn, sum);
        }
        return tot - mn;   
    }
};