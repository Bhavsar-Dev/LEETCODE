class Solution {
    public int distinctSubseqII(String s) {
        final long MOD = 1000000007;
        long dp = 1;
        long[] la = new long[26];
        for(char c: s.toCharArray()) {
            int i = c - 'a';
            long ndp = (2 * dp - la[i] + MOD) % MOD;
            la[i] = dp;
            dp = ndp;
        }
        return (int)((dp - 1+ MOD) % MOD);
    }
}