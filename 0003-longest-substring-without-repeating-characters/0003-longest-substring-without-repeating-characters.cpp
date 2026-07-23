class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> la(256, -1);
        int l = 0, ans = 0;
        for(int r = 0; r < s.size(); ++r) {
            l = max(l, la[s[r]]+1);
            la[s[r]] = r;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};