class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> pal(n, vector<bool>(n, false));
        for(int len = 1; len <= n; ++len) {
            for(int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                if(s[i] == s[j]) {
                    if(len <= 2) {
                        pal[i][j] = true;
                    }
                    else pal[i][j] = pal[i + 1][j - 1];
                }
            }
        }
        vector<int> dp(n + 1, 0);
        for(int i = n - 1; i >= 0; --i) {
            dp[i] = INT_MAX;
            for(int j = i; j < n; ++j) {
                if(pal[i][j]) {
                    if(j == n - 1) dp[i] = 0;
                    else dp[i] = min(dp[i], 1 + dp[j + 1]);
                }
            }
        }
        return dp[0];
    }
};