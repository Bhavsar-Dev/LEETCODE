class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int st = 0, maxl= 1;
        for(int len = 1;len <= n; ++len) {
            for(int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                if(s[i] == s[j]) {
                    if(len <= 2) dp[i][j] = true;
                    else dp[i][j] = dp[i + 1][j - 1];
                }
                if(dp[i][j] && len > maxl) {
                    maxl = len;
                    st = i;
                }
            }
        }
        return s.substr(st, maxl);
    }
};