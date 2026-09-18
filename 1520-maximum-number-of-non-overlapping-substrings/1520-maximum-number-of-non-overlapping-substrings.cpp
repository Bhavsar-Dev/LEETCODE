class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, n), last(26, -1);
        for(int i = 0; i < n; i++) {
            first[s[i] - 'a'] = min(first[s[i] - 'a'], i);
            last[s[i] - 'a'] = i;
        }
        vector<pair<int, int>> intervals;
        for(int c = 0; c < 26; c++) {
            if(last[c] == -1) continue;
            int L = first[c];
            int R = last[c];
            bool valid = true;
            for(int i = L; i <= R && valid; i++){
                int ch = s[i] - 'a';
                if(first[ch] < L) {
                    valid = false;
                    break;
                }
                R = max(R, last[ch]);
            }
            if(valid) intervals.push_back({L, R});
        }
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) { return a.second < b.second; });
        vector<string> ans;
        int prev = -1;
        for(auto &[L, R] : intervals) {
            if(L > prev) {
                ans.push_back(s.substr(L, R - L + 1));
                prev = R;
            }
        }
        return ans;
    }
};