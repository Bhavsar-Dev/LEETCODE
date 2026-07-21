class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int on = 0;
        for(char c : s) {
            if(c == '1') on++;
        }   
        vector<pair<char, int>> run;
        for(char c : s) {
            if(run.empty() || run.back().first != c) run.push_back({c, 1});
            else run.back().second++;
        }
        int gain  = 0;
        for(int i = 1; i + 1 < run.size(); ++i) {
            if(run[i].first == '1' && run[i - 1].first == '0' && run[i + 1].first == '0') {
                gain = max(gain, run[i - 1].second + run[i +1].second);
            }
        }
        return on + gain;
    }
};