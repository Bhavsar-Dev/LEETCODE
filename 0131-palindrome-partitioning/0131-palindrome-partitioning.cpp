class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> pal(n, vector<bool>(n, false));
        for(int len = 1; len <= n; ++len) {
            for(int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                if(s[i] == s[j]) {
                    if(len <= 2) pal[i][j] =true;
                    else pal[i][j] = pal[i + 1][j - 1];
                }
            }
        }
        vector<vector<vector<string>>> dp(n + 1);
        dp[n].push_back({});
        for(int i = n - 1; i >= 0; --i) {
            for(int j = i; j < n; ++j) {
                if(pal[i][j]) {
                    string cur = s.substr(i, j - i + 1);
                    for(auto part : dp[j + 1]) {
                        part.insert(part.begin(), cur);
                        dp[i].push_back(part);
                    }
                }
            }
        }
        return dp[0];
    }
};