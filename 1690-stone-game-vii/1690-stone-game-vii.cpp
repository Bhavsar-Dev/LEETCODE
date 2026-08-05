class Solution {
public:
vector<int> pre;
vector<vector<int>> dp;
int sum(int l, int r) {
    return pre[r + 1] - pre[l];
}
int solve(int l, int r) {
    if(l == r) return 0;
    if(dp[l][r] != -1) return dp[l][r];
    int left = sum(l + 1, r) - solve(l +1, r);
    int right = sum(l, r - 1) - solve(l, r - 1);
    return dp[l][r] = max(left, right);
}
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        pre.assign(n + 1, 0);
        for(int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + stones[i];
        }
        dp.assign(n, vector<int>(n, -1));
        return solve(0, n - 1);
    }
};