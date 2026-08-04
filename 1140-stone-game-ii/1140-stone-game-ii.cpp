class Solution {
public:
int n;
vector<int> suf;
vector<vector<int>> dp;
int solve(int i, int m) {
    if(i >= n) return 0;
    if(2 * m >= n - i) return suf[i];
    if(dp[i][m] != -1) return dp[i][m];
    int ans = 0;
    for(int x = 1; x <= 2 * m; ++x) {
        ans = max(ans, suf[i] - solve(i + x, max(m, x)));
    }
    return dp[i][m] = ans;  
}
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        suf.assign(n + 1, 0);
        for(int i = n - 1; i >= 0; --i) {
            suf[i] = suf[i + 1] + piles[i]; 
        }
        dp.assign(n, vector<int>(n + 1, -1));
        return solve(0, 1);
    }
};