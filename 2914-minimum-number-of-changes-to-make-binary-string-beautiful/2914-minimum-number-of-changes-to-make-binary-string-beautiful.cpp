class Solution {
public:
    int minChanges(string s) {
        int minr = 0;
        for(int i = 0; i < s.length(); i += 2) {
            if(s[i] != s[i + 1]) minr++;
        }
        return minr;
    }
};