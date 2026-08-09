

class Solution {
public:
unordered_set<string> st;
vector<int> dp;
bool solve(string &s, int i) {
    if(i == s.size()) return true;
    if(dp[i] != -1) return dp[i];
    for(int j = i; j < s.size(); ++j) {
        string temp = s.substr(i, j - i + 1);
        if(st.count(temp) && solve(s, j +1)) return dp[i] = true;
    }
    return dp[i] = false;
}
    bool wordBreak(string s, vector<string>& wordDict) {
        //tABULATION
        // int n = s.size();
        // unordered_set<string> st(wordDict.begin(), wordDict.end());
        // vector<bool> dp(n + 1, false);
        // dp[0] = true;
        // for(int i = 1; i <= n; ++i) {
        //     for(int j = 0; j < i; ++j) {
        //         if(dp[j] && st.count(s.substr(j, i - j))) {
        //             dp[i] = true;
        //             break;
        //         }
        //     }
        // }
        // return dp[n];

        //MEMO
        st = unordered_set<string>(wordDict.begin(), wordDict.end());
        dp.resize(s.size(), -1);
        return solve(s, 0);
    }
};