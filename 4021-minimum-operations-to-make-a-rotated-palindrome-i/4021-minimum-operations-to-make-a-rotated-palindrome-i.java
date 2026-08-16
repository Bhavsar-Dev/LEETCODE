class Solution {
    public int minOperations(String s) {
        int n = s.length();
        int ans = Integer.MAX_VALUE;
        for(int r = 0; r < n; ++r) {
            int cst= r;
            for(int i= 0; i < n / 2; ++i) {
                int j= n - 1- i;
                int a = s.charAt((i + r) % n) - 'a';
                int b = s.charAt((j + r) % n) - 'a';
                int x = (b - a + 26) % 26;
                int y = (a - b + 26) % 26;
                cst += Math.min(x, y);
            }
            ans = Math.min(ans, cst);
        }
        return ans;
    }
}