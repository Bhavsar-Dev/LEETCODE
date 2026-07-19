class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int maxp = 0;
        int n = prices.size();
        for(int i = 0; i < n; ++i) {
            int cst = prices[i] - mini;
            maxp = max(maxp, cst);
            mini = min(mini, prices[i]);
        }
        return maxp;
    }
};