class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n + 1, 0);
        for(auto &q : shifts) {
            int l = q[0], r = q[1], dir = q[2];
            if(dir == 1) {
                diff[l]++;
                diff[r + 1]--;
            }
            else {
                diff[l]--;
                diff[r + 1]++;
            }
        }
        int shift = 0;
        for(int i = 0; i < n; ++i) {
            shift += diff[i];
            int cur = s[i] - 'a';
            cur = (cur + shift) % 26;
            if(cur < 0) cur += 26;
            s[i] = char(cur + 'a');
        }
        return s;
    }
};