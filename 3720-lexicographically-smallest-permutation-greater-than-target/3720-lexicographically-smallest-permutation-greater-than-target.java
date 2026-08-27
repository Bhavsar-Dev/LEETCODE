class Solution {
    public String lexGreaterPermutation(String s, String target) {
        int n = s.length();
        int[] cnt = new int[26];
        for(char c : s.toCharArray()) {
            cnt[c - 'a']++;
        }
        int best = -1;
        int bestChar = -1;
        for(int i = 0; i < n; i++) {
            int t = target.charAt(i) - 'a';
            for(int c = t + 1; c < 26; c++) {
                if(cnt[c] > 0) {
                    best = i;
                    bestChar = c;
                    break;
                }
            }
            if(cnt[t] == 0) {
                break;
            }
            cnt[t]--;
        }
        if(best == -1) {
            return "";
        }
        cnt = new int[26];
        for(char c : s.toCharArray()) {
            cnt[c - 'a']++;
        }
        StringBuilder ans = new StringBuilder();
        for(int i = 0; i < best; i++) {
            char c = target.charAt(i);
            ans.append(c);
            cnt[c - 'a']--;
        }
        int t = target.charAt(best) - 'a';
        for(int c = t + 1; c < 26; c++) {
            if(cnt[c] > 0) {
                ans.append((char) ('a' + c));
                cnt[c]--;
                break;
            }
        }
        for(int c = 0; c < 26; c++) {
            while(cnt[c] > 0) {
                ans.append((char) ('a' + c));
                cnt[c]--;
            }
        }
        return ans.toString();
    }
}