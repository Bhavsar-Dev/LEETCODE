class Solution {
    public String lexPalindromicPermutation(String s, String target) {
        int n = s.length();
        int[] c = new int[26];
        for(char x : s.toCharArray()) {
            c[x - 'a']++;
        }
        int odd = 0, mid = -1;
        for(int i = 0; i < 26; i++) {
            if(c[i] % 2 == 1) {
                odd++;
                mid = i;
            }
        }
        if(odd > 1) return "";
        int[] h = new int[26];
        for(int i = 0; i < 26; i++) {
            h[i] = c[i] / 2;
        }
        int m = n / 2;
        String t = target.substring(0, m);
        String p = get(t, h);
        if(p == null) return "";
        String ans = make(p, mid, n);
        if(ans.compareTo(target) > 0) {
            return ans;
        }
        p = next(p);
        if(p == null) return "";
        return make(p, mid, n);
    }
    private String get(String t, int[] c) {
        int n = t.length();
        StringBuilder s = new StringBuilder();
        for(int i = 0; i < n; i++) {
            int x = t.charAt(i) - 'a';
            if(c[x] > 0) {
                s.append((char) ('a' + x));
                c[x]--;
            } 
            else {
                for(int j = x + 1; j < 26; j++) {
                    if(c[j] > 0) {
                        s.append((char) ('a' + j));
                        c[j]--;
                        add(s, c);
                        return s.toString();
                    }
                }
                for(int j = i - 1; j >= 0; j--) {
                    int y = s.charAt(j) - 'a';
                    c[y]++;
                    for(int k = y + 1; k < 26; k++) {
                        if(c[k] > 0) {
                            StringBuilder r = new StringBuilder(s.substring(0, j));
                            r.append((char) ('a' + k));
                            c[k]--;
                            add(r, c);
                            return r.toString();
                        }
                    }
                }
                return null;
            }
        }
        return s.toString();
    }
    private void add(StringBuilder s, int[] c) {
        for(int i = 0; i < 26; i++) {
            while(c[i] > 0) {
                s.append((char) ('a' + i));
                c[i]--;
            }
        }
    }
    private String next(String s) {
        char[] a = s.toCharArray();
        int i = a.length - 2;
        while(i >= 0 && a[i] >= a[i + 1]) {
            i--;
        }
        if(i < 0) return null;
        int j = a.length - 1;
        while(a[j] <= a[i]) {
            j--;
        }
        char x = a[i];
        a[i] = a[j];
        a[j] = x;
        int l = i + 1, r = a.length - 1;
        while(l < r) {
            x = a[l];
            a[l] = a[r];
            a[r] = x;
            l++;
            r--;
        }
        return new String(a);
    }
    private String make(String s, int mid, int n) {
        StringBuilder a = new StringBuilder(s);
        if(n % 2 == 1) {
            a.append((char) ('a' + mid));
        }
        for(int i = s.length() - 1; i >= 0; i--) {
            a.append(s.charAt(i));
        }
        return a.toString();
    }
}