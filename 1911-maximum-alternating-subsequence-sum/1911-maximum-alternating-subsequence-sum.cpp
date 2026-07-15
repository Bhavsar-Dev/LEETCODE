class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));
        for(int i = n - 1; i >= 0; --i) {
            dp[i][0] = max(dp[i + 1][0], nums[i] + dp[i + 1][1]);
            dp[i][1] = max(dp[i + 1][1], -1LL * nums[i] + dp[i + 1][0]);
        }
        return dp[0][0];
    }
};