class Solution {
public:
    static const int MOD = 1000000007;
    int dp[205][201][201];
    int solve(int i, int g1, int g2, vector<int>& nums) {
        if(i == nums.size()) return (g1 > 0 && g2 > 0 && g1 == g2);
        int &ans = dp[i][g1][g2];
        if(ans != -1) return ans;
        long long res = 0;
        res += solve(i + 1, g1, g2, nums);
        int ng1 = (g1 == 0) ? nums[i] : gcd(g1, nums[i]);
        res += solve(i + 1, ng1, g2, nums);
        int ng2 = (g2 == 0) ? nums[i] : gcd(g2, nums[i]);
        res += solve(i + 1, g1, ng2, nums);
        return ans = res % MOD;
    }
    int subsequencePairCount(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, nums);
    }
};