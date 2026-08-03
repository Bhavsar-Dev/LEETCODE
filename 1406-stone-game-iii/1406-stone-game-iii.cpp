class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(4, 0);
        for(int i = n - 1; i >= 0; --i) {
            int maxd = INT_MIN;
            int cur = 0;
            for(int k = 0; k < 3 && i + k < n; ++k) {
                cur += stoneValue[i + k];
                int opp = dp[(i + k + 1) % 4];
                maxd = max(maxd, cur - opp);
            }
            dp[i % 4] = maxd;
        }
        int res = dp[0];
        if(res > 0) return "Alice";
        if(res < 0) return "Bob";
        return "Tie";
    }
};