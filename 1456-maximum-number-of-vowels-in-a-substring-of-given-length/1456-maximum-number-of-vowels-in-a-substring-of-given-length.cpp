class Solution {
public:
    bool vow(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxVowels(string s, int k) {
        int cnt = 0;
        for(int i = 0; i < k; ++i) {
            if(vow(s[i])) cnt++;
        }
        int ans = cnt;
        for(int i = k; i < s.size(); ++i) {
            if(vow(s[i])) cnt++;
            if(vow(s[i - k])) cnt--;
            ans = max(ans, cnt);
        }
        return ans;
    }
};