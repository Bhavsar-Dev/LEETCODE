class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";
        vector<int> ne(128, 0);
        for(char c: t) ne[c]++;
        int l = 0, cnt = 0, st = 0, len = INT_MAX;
        for(int r = 0; r < s.size(); ++r) {
            if(ne[s[r]] > 0) cnt++;
            ne[s[r]]--;
            while(cnt == t.size()) {
                if(r - l + 1 < len) {
                    len = r - l  +1;
                    st = l;
                }
                ne[s[l]]++;
                if(ne[s[l]] > 0) cnt--;
                l++;
            }
        }
        if(len == INT_MAX) return "";
        return s.substr(st, len);
    } 
}; 