class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.size();
        string ans = "";
        for(int i = 0; i < n; ++i) {
            int lo = 0, up = 0;
            for(int j = i; j < n; ++j) {
                if(islower(s[j])) lo |= 1 << (s[j] - 'a');
                else up |= 1 << (s[j] - 'A');
                if(lo == up && j - i + 1 > ans.size()) {
                    ans = s.substr(i, j - i + 1);
                }
            }
        }
        return ans;
    }
};